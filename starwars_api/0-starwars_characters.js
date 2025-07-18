#!/usr/bin/node
const request = require('request');
const epNumber = process.argv[2];
const urlPath = 'https://swapi-api.hbtn.io/api/films/' + epNumber;

request(urlPath, async (err, response, body) => {
  if (err) throw err;
  const movies = JSON.parse(body);
  const characters = movies.characters;

  for (const characterUrl of characters) {
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
