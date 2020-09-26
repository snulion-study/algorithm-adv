import math
# 근의 공식
def root_equation(b,c):
    return ((-b+math.sqrt(b**2-4*c))/2, (-b-math.sqrt(b**2-4*c))/2)

def solution(brown, yellow):
    answer = []
    # 근과 계수와의 관계로 이차방정식 풀기...
    sum_ = brown//2 + 2
    product_ = brown+yellow
    m,n = root_equation(-1*sum_, product_)

    answer.append(int(m))
    answer.append(int(n))
    return answer



print(solution(10,2))
print(solution(8,1))
print(solution(24,24))