#!/usr/bin/env python

"""
synopsis:
    Simple Pirate worker
    Connects REQ socket to tcp://*:5556
    Implements worker part of LRU queueing
    Original author: Daniel Lundin <dln(at)eintr(dot)org>
    Modified for async/ioloop: Dave Kuhlman <dkuhlman(at)davekuhlman(dot)org>
usage:
    python spworker.py
notes:
    To test this, use the lazy pirate client.  To run this, start any number of
    spworker.py processes, one instance of an spqueue.py process, and any
    number lpclient.py processes, in any order.
"""


import sys
from random import randint
from functools import partial
import zmq
from zmq.eventloop.future import Context
from zmq.eventloop.ioloop import IOLoop
from tornado import gen

LRU_READY = "\x01"


@gen.coroutine
def run_worker():
    context = Context(1)
    worker = context.socket(zmq.REQ)

    identity = "%04X-%04X" % (randint(0, 0x10000), randint(0, 0x10000))
    worker.setsockopt_string(zmq.IDENTITY, identity)
    worker.connect("tcp://localhost:5556")

    print("I: (%s) worker ready" % identity)
    yield worker.send_string(LRU_READY)

    cycles = 0
    while True:
        msg = yield worker.recv_multipart()
        if not msg:
            break

        cycles += 1
        if cycles > 3 and randint(0, 5) == 0:
            print("I: (%s) simulating a crash" % identity)
            break
        elif cycles > 3 and randint(0, 5) == 0:
            print("I: (%s) simulating CPU overload" % identity)
            yield gen.sleep(3)
        print("I: (%s) normal reply" % identity)
        # Do some heavy work
        yield gen.sleep(1)
        yield worker.send_multipart(msg)


@gen.coroutine
def run(loop):
    while True:
        yield run_worker()


def main():
    args = sys.argv[1:]
    if len(args) != 0:
        sys.exit(__doc__)
    try:
        loop = IOLoop.current()
        loop.run_sync(partial(run, loop))
    except KeyboardInterrupt:
        print('\nFinished (interrupted)')


if __name__ == '__main__':
    main()
