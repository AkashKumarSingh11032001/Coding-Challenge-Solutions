N = int(input())
len = N
minimum_val = 0
for i in range(0,len):
    for j in range(0,len):
        if i  < j :
            minimum_val = i
        else:
            minimum_val = j

        if minimum_val < len-i:
            minimum_val = minimum_val
        else:
            minimum_val = len-i-1
        
        if minimum_val < len-j-1:
            minimum_val = minimum_val
        else:
            minimum_val = len-j-1

        print(N-minimum_val,end = " ")

    print()