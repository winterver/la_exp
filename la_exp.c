#include <stdio.h>
#define exp_t long long

/*
def _printnum_comma(num):
    if num < 1000:
        printf("%d", num)
        return
    _printnum_comma(num//1000)
    printf(",%03d", num%1000)

def printnum_comma(num, end='\n'):
    _printnum_comma(num)
    printf(end)
*/
void printexp(exp_t xp) {
    if (xp < 1000) { printf("%lld", xp); return; }
    printexp(xp / 1000); printf(",%03lld", xp % 1000);
}

/*
def ulv_req_exp(ulv):
    return (ulv+399) * 100000000
*/
#define ulv_req_exp(ulv) ((ulv+399)*100000000LL)

/*
def ulv_to_exp(ulv, per=0):
    up = ulv_req_exp(1)
    down = ulv_req_exp(ulv-1)
    exp = (up+down) * (ulv-1) / 2
    exp += per * ulv_req_exp(ulv)
    return int(exp)
*/
exp_t ulv_to_exp(int ulv, int per) {
    exp_t up = ulv_req_exp(1);
    exp_t down = ulv_req_exp(ulv - 1);
    exp_t exp = (up + down) * (ulv - 1) / 2;
    return exp + ulv_req_exp(ulv) * per / 10000;
}

/*
def exp_to_ulv(exp):
    ulv = 1
    per = 0
    while exp >= ulv_req_exp(ulv):
        exp -= ulv_req_exp(ulv)
        ulv += 1
    per = exp / ulv_req_exp(ulv)
    return (ulv, per)
*/
void exp_to_ulv(exp_t exp, int* ulv, int* per) {
    for (*ulv = 1; exp >= ulv_req_exp(*ulv); *ulv += 1) {
        exp -= ulv_req_exp(*ulv);
    }
    *per = exp * 10000 / ulv_req_exp(*ulv);
}

void exp_to_ulv2(exp_t exp) {
    int ulv = 1, per = 0;
    while (exp >= ulv_req_exp(ulv)) {
        exp -= ulv_req_exp(ulv);
        ulv += 1;
    }
    per = exp * 10000 / ulv_req_exp(ulv);
    printf("%d %02d.%02d%%\n", ulv, per/100, per%100);
}

int main() {
    printexp(ulv_to_exp(4886, 4774)); putchar('\n');
}
