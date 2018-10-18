// use jasmine to run this file
// https://jasmine.github.io
//
// npm install -g jasmine
// jasmine <this_file>

const juggle = require('./juggler_seq');

describe("", () => {

  it('should print the juggler sequence starting on 3', () => {    
  	expect(juggle(3)).toEqual([3,5,11,36,6,2,1]);
  });

   it('should print the juggler sequence starting on 6', () => {    
  	expect(juggle(6)).toEqual([6,2,1]);
  });


});