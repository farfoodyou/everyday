# coding --utf-8--
import time

def time_me(fn):
    def _wrapper(*args, **kwargs):
        start = time.time()
        fn(*args, **kwargs)
        print("%s cost %s second \n"%(fn.__name__, time.time() - start))
    return _wrapper

@time_me
def solve():
    data = {}
    
solve()

def wrapper(fn):
    def _wrapper(*args, **kwargv):
        print("%s start",fn.__name__)
        fn(*args, **kwargv)
        print("%s end",fn.__name__)
    return _wrapper