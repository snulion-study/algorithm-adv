def solution(bridge_length, weight, truck_weights):
    answer = 0
    bridge = [0 for i in range(bridge_length)]
    
    while len(truck_weights) != 0 or sum(bridge):
        answer += 1
        bridge.pop(0)
        bridge.append(truck_weights.pop(0) if truck_weights != [] \
                and sum(bridge) + truck_weights[0] <= weight else 0)     
    return answer                           