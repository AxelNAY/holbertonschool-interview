#!/usr/bin/node
const request = require('request');
const epNumber = process.argv[2];
if (!epNumber) {
    console.log('Use: ./0-starwars_characters.js <episode Number>');
    process.exit(1);
}
const urlPath = 'https://swapi-api.hbtn.io/api/films/' + epNumber;
request(urlPath, function (err, response, body) {
    if (err) throw err;
    const movie = JSON.parse(body).results;
    console.log(movie);
    for (const character of movie.characters) {
        console.log(character);
    }
});
