node-autoreleasepool
====================
### A very simple wrapper around the OS X NSAutoreleasePool, for [NodeJS][Node].


This module offers dead-simple NSAutoreleasePool functionality. It's more likely
meant for use by other Objective-C native modules, so that multiple autorelease
pools don't have to be created constantly.

This module takes care of creating an NSAutoreleasePool the first time it's required
that may be used automatically by any other Objective-C calls that require one.

It also hookds onto the `process`'s '_exit_' event to drain teh shared autorelease pool
at the last possible moment.


Dead-Simple Usage
-----------------

    // Takes care of setting up a shared NSAutoreleasePool
    require('autoreleasepool');

    // Now do other things in Obj-C land and the runtime won't display
    // the "no autorelease pool, just leaking" message.


[Node]: http://nodejs.org
