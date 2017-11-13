#!/usr/bin/env python

import multiprocessing as mp

gDict = {'global_constant':10}

def MPfunction(input):
    global gDict
    input += gDict['global_constant']
    return input


def main():
    pool = mp.Pool(mp.cpu_count())

    try:
        dataList = [0, 1, 2, 3]
        data = pool.map(MPfunction, dataList, chunksize=10)
        print(data)
    finally:
        pool.close()
        pool.join()


if __name__ == '__main__':

	main()




