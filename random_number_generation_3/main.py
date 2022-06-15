import random

matrix = [[0.2, 0.1, 0, 0.05], [0, 0.1, 0, 0.05], [0.05, 0, 0.1, 0], [0.05, 0, 0.1, 0.2]]
x1_sum = [0 for i in range(len(matrix))]
x2_sum = [[0 for _ in range(len(matrix))] for _ in range(len(matrix))]
for i in range(len(matrix)):
    x1_sum[i] = sum(matrix[i])
    if i > 0:
        x1_sum[i] += x1_sum[i-1]
    for j in range(len(matrix[i])):
        x2_sum[i][j] = matrix[i][j]
        if j > 0:
            x2_sum[i][j] += x2_sum[i][j-1]

results = [[0 for _ in range(len(matrix))] for _ in range(len(matrix))]
for i in range(100000):
    rand = random.random()
    result1 = 0
    for i in range(len(matrix)):
        if x1_sum[i] > rand:
            result = i
            rand2 = random.uniform(0, sum(matrix[i]))
            for j in range(len(matrix[i])):
                if x2_sum[i][j] > rand2:
                    result2 = j
                    results[i][j] += 1
                    break
            break

for i in range(len(results)):
    for j in range(len(results[i])):
        print("("+str(i+1)+","+str(j+1)+"): "+str(results[i][j]))