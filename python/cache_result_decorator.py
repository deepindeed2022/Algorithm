import collections
import functools
global count
class memoized(object):
   '''Decorator. Caches a function's return value each time it is called.
   If called later with the same arguments, the cached value is returned
   (not reevaluated).
   '''
   def __init__(self, func):
      global count
      count = 0
      self.func = func
      self.cache = {}

   def __call__(self, *args):
      global count
      count+=1
      print count
      if not isinstance(args, collections.Hashable):
         # uncacheable. a list, for instance.
         # better to not cache than blow up.
         return self.func(*args)

      if args in self.cache:
         return self.cache[args]
      else:
         value = self.func(*args)
         self.cache[args] = value
         return value

   def __repr__(self):
      '''Return the function's docstring.'''
      print  "__repr__"
      return self.func.__doc__

   def __get__(self, obj, objtype):
      '''Support instance methods.'''
      print  "__get__"
      return functools.partial(self.__call__, obj)

@memoized
def fibonacci(n):
   "Return the nth fibonacci number."
   if n in (0, 1):
      return n
   return fibonacci(n-1) + fibonacci(n-2)

print fibonacci(123)
