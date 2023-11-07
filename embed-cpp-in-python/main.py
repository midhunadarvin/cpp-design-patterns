
import numpy
from my_sum import *

array = numpy.arange(0, 100000000, 1, numpy.int32)

# 3. call function mysum
array_sum = mylib.mysum(len(array), array)

print('sum of array: {}'.format(array_sum))