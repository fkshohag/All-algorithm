def findTotalPower(power):
    ans = 0
    for i in range(0, len(power)):
        for j in range(i, len(power)):
            ans = ans + min(power[i:j+1]) * power[j]
    return ans
        
        
    
res = findTotalPower([2, 3, 2,1])
print(res)

# ans = 27
