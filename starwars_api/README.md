# Star Wars API - Character Fetcher

## Description

This project implements a Node.js script that fetches and displays all characters from a specific Star Wars movie using the [Star Wars API (SWAPI)](https://swapi-api.hbtn.io/). The script retrieves character data in the correct order as they appear in the film's API response, using asynchronous operations with promises and the `request` module.

## Features

- **Sequential Character Display**: Prints character names in the exact order they appear in the movie's character list
- **Asynchronous Operations**: Uses async/await with promises for clean asynchronous code
- **API Integration**: Fetches data from the Star Wars API (SWAPI)
- **Error Handling**: Includes error handling for failed API requests
- **Command-Line Interface**: Accepts movie ID as a command-line argument

## Requirements

- **Node.js**: Version 10.x or higher (for async/await support)
- **npm**: For package management
- **request** module: For making HTTP requests

## Installation

### Install Dependencies
```bash
npm install
```

This will install the required packages from `package.json`:
- `request@^2.88.2` - HTTP client for making API requests

## Files

| File | Description |
|------|-------------|
| `0-starwars_characters.js` | Main script to fetch and display Star Wars characters |
| `package.json` | Project configuration and dependencies |
| `package-lock.json` | Locked versions of dependencies |
| `README.md` | Project documentation |

## Usage

### Basic Usage
```bash
./0-starwars_characters.js <movie_id>
```

or
```bash
node 0-starwars_characters.js <movie_id>
```

### Movie IDs

The Star Wars API uses the following movie IDs:

| Movie ID | Movie Title |
|----------|-------------|
| 1 | A New Hope (Episode IV) |
| 2 | The Empire Strikes Back (Episode V) |
| 3 | Return of the Jedi (Episode VI) |
| 4 | The Phantom Menace (Episode I) |
| 5 | Attack of the Clones (Episode II) |
| 6 | Revenge of the Sith (Episode III) |

### Examples

**Example 1: Return of the Jedi (Movie ID 3)**
```bash
./0-starwars_characters.js 3
```

**Output:**
```
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

**Example 2: A New Hope (Movie ID 1)**
```bash
./0-starwars_characters.js 1
```

**Output:**
```
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Owen Lars
Beru Whitesun lars
R5-D4
Biggs Darklighter
Obi-Wan Kenobi
Wilhuff Tarkin
Chewbacca
Han Solo
Greedo
Jabba Desilijic Tiure
Wedge Antilles
Jek Tono Porkins
Raymus Antilles
```

## How It Works

### API Endpoints

1. **Film Endpoint**: `https://swapi-api.hbtn.io/api/films/{movie_id}`
   - Returns movie details including a `characters` array with character URLs

2. **Character Endpoint**: `https://swapi-api.hbtn.io/api/people/{character_id}`
   - Returns detailed character information including `name`

### Algorithm
```javascript
1. Accept movie ID from command line arguments
2. Fetch movie data from films endpoint
3. Extract characters array (list of character URLs)
4. For each character URL (in order):
   a. Wait for the previous request to complete
   b. Make HTTP request to character URL
   c. Parse JSON response
   d. Print character name
   e. Continue to next character
5. Maintain order using sequential async/await
```

### Code Breakdown
```javascript
#!/usr/bin/node
const request = require('request');
const epNumber = process.argv[2];
const urlPath = 'https://swapi-api.hbtn.io/api/films/' + epNumber;

request(urlPath, async (err, response, body) => {
  if (err) throw err;
  
  // Parse movie data
  const movies = JSON.parse(body);
  const characters = movies.characters;

  // Sequential processing using for...of loop
  for (const characterUrl of characters) {
    // Wait for each character request to complete
    await new Promise((resolve, reject) => {
      request(characterUrl, (err, response, body) => {
        if (err) reject(err);
        const character = JSON.parse(body);
        console.log(character.name);
        resolve();
      });
    });
  }
});
```

## Key Concepts

### Async/Await with Promises

The script uses **async/await** to ensure characters are printed in order:
```javascript
// Wraps callback-based request in a Promise
await new Promise((resolve, reject) => {
  request(characterUrl, (err, response, body) => {
    if (err) reject(err);
    // Process response...
    resolve();  // Signal completion
  });
});
```

### Sequential Execution

Using `for...of` with `await` ensures **sequential execution**:
```javascript
for (const characterUrl of characters) {
  await fetchCharacter(characterUrl);  // Waits for each to complete
}
```

**vs. Parallel execution (wrong for this task):**
```javascript
characters.forEach(characterUrl => {
  fetchCharacter(characterUrl);  // All run simultaneously, random order
});
```

## API Response Structure

### Film Response
```json
{
  "title": "Return of the Jedi",
  "episode_id": 6,
  "characters": [
    "https://swapi-api.hbtn.io/api/people/1/",
    "https://swapi-api.hbtn.io/api/people/2/",
    "https://swapi-api.hbtn.io/api/people/3/"
    // ... more character URLs
  ],
  // ... other fields
}
```

### Character Response
```json
{
  "name": "Luke Skywalker",
  "height": "172",
  "mass": "77",
  "hair_color": "blond",
  "skin_color": "fair",
  "eye_color": "blue",
  // ... other fields
}
```

## Error Handling

The script includes basic error handling:
```javascript
if (err) throw err;  // In main request

if (err) reject(err);  // In character request
```

**Potential errors:**
- Invalid movie ID
- Network connectivity issues
- API server downtime
- Malformed JSON responses

## Performance Considerations

### Sequential vs. Parallel

**Current Implementation (Sequential):**
- **Pros**: Guarantees correct order, simple logic
- **Cons**: Slower (waits for each request)
- **Time**: ~20 characters × ~200ms = ~4 seconds

**Parallel Alternative (Not Used):**
- **Pros**: Much faster (all requests at once)
- **Cons**: Requires complex ordering logic
- **Time**: ~200ms total (network bound)

## Dependencies

### request (v2.88.2)

**Note**: The `request` module is deprecated as of 2020. For new projects, consider alternatives:

- **axios**: Popular promise-based HTTP client
- **node-fetch**: Fetch API for Node.js
- **got**: Modern HTTP request library

**Example with axios:**
```javascript
const axios = require('axios');

const response = await axios.get(characterUrl);
console.log(response.data.name);
```

## Troubleshooting

### Common Issues

**Issue**: `./0-starwars_characters.js: Permission denied`
```bash
chmod +x 0-starwars_characters.js
```

**Issue**: `request is not defined`
```bash
npm install
```

**Issue**: `Invalid movie ID` (no output)
- Verify movie ID is between 1-6
- Check API availability

**Issue**: `SyntaxError: Unexpected token`
- Ensure Node.js version supports async/await (v10+)
- Check Node version: `node --version`

## Development

### Code Style

The project uses `semistandard` for code linting:
```bash
npm run test  # Runs linting (currently just exits)
```

### Modifying the Script

To fetch additional character information:
```javascript
const character = JSON.parse(body);
console.log(`${character.name} (${character.height}cm)`);
// Output: Luke Skywalker (172cm)
```

## Alternatives and Extensions

### Fetch Multiple Movies
```javascript
const movieIds = [1, 2, 3];
for (const id of movieIds) {
  console.log(`\n=== Movie ${id} ===`);
  await fetchMovieCharacters(id);
}
```

### Add Character Details
```javascript
console.log(`${character.name}`);
console.log(`  Height: ${character.height}cm`);
console.log(`  Birth Year: ${character.birth_year}`);
```

### Cache API Responses
```javascript
const cache = {};
if (cache[url]) {
  return cache[url];
} else {
  const data = await fetchData(url);
  cache[url] = data;
  return data;
}
```

## API Documentation

Full SWAPI documentation: [https://swapi.dev/documentation](https://swapi.dev/documentation)

**Available Resources:**
- Films
- People (Characters)
- Planets
- Species
- Starships
- Vehicles

## License

ISC

## Author

Project implementation for understanding asynchronous JavaScript, API integration, and sequential promise handling in Node.js applications.
