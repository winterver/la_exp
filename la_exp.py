#!/usr/bin/python3

def printf(fmt, *args):
    print(fmt % args, end='')

def _printnum_comma(num):
    if num < 1000:
        printf("%d", num)
        return
    _printnum_comma(num//1000)
    printf(",%03d", num%1000)

def printnum_comma(num, end='\n'):
    if num < 0:
        printf("-")
        num = -num
    _printnum_comma(num)
    printf(end)

def ulv_req_exp(ulv):
    return (ulv+399) * 100000000

def ulv_to_exp(ulv, per=0):
    up = ulv_req_exp(1)
    down = ulv_req_exp(ulv-1)
    exp = (up+down) * (ulv-1) / 2
    exp += per * ulv_req_exp(ulv)
    return int(exp)

def exp_to_ulv(exp):
    ulv = 1
    per = 0
    while exp >= ulv_req_exp(ulv):
        exp -= ulv_req_exp(ulv)
        ulv += 1
    per = exp / ulv_req_exp(ulv)
    return (ulv, per)

def ulv_add_exp(ulv, per, exp):
    exp += ulv_to_exp(ulv, per)
    return exp_to_ulv(exp)

def ulv_to_ulv_req_exp(ulv, per, hulv, hper):
    return ulv_to_exp(hulv, hper) - ulv_to_exp(ulv, per)

print(ulv_add_exp(4886, 0.4774, 66000000000000))
