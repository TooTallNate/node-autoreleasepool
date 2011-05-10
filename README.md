node-autoreleasepool
====================
### A very simple wrapper around the OS X [NSAutoreleasePool][], for [NodeJS][Node].


This module offers dead-simple [NSAutoreleasePool] functionality. It's more likely
meant for use by other Objective-C native modules, so that multiple autorelease
pools don't have to be created constantly.

This module takes care of creating an NSAutoreleasePool the first time it's required
that may be used automatically by any other Objective-C calls that require one.

It also hooks onto the `process`'s '_exit_' event in order to drain the shared
autorelease pool at the last possible moment.


Dead-Simple Usage
-----------------

    // Takes care of setting up a shared NSAutoreleasePool
    require('autoreleasepool');

    // Now do other things in Obj-C land and the runtime won't display
    // the "no autorelease pool, just leaking" message.


API
---

If you, for some weird reason, need to create another `NSAutoreleasePool`
instance, it's simple to do so:

    var pool = new autoreleasepool.AutoreleasePool();

The most recent autoreleasepool in the call stack is the one used when creating
new Objective-C objects with `autorelease`.

The only function available to the `NSAutoreleasePool` instance is `drain()`,
which drains the autorelease pool, and should be called when the program is
exiting.


[Node]: http://nodejs.org
[NSAutoreleasePool]: http://developer.apple.com/library/mac/documentation/Cocoa/Reference/Foundation/Classes/NSAutoreleasePool_Class/Reference/Reference.html
