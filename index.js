// Export the 'AutoreleasePool' constructor, in case the user want to create
// another autorelease pool from the default one created below...
module.exports = require('./build/default/binding.node');

// A "default" pool is created the first time this module is require'd, so
// any module requireing NSAutoreleasePool functionality just needs to require this
// module, nothing else is required on the developer's part
var pool = new (module.exports.AutoreleasePool)();

// We hook onto the process' 'exit' event in order to ensure that we drain
// at the last possible moment.
process.on('exit', pool.drain.bind(pool));
