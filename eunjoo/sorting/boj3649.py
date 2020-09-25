import sys
input = sys.stdin.readline

while True:
    try:
        x = int(input())*pow(10, 7)
        legos = [int(input()) for _ in range(int(input()))]
        legos.sort()
        src, des, ans = 0, len(legos)-1, "danger"
        while src < des:
            sum = legos[src] + legos[des]
            if sum == x:
                ans = "yes " + str(min(legos[src], legos[des])) \
                        + str(" ") +  str(max(legos[src], legos[des]))
                break
            elif sum < x:
                src += 1
            else:
                des -= 1
        print(ans)

    except:
        break
