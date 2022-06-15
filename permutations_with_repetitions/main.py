def permutations(l, n):
    if n == 0:
        return [[]]

    ltr = []  # list to return
    for i in range(len(l)):
        m = l[i]
        for p in permutations(l, n - 1):
            ltr.append([m] + p)

    return ltr


input_arr = [1, 2, 3, 4, 5]
output_arr = permutations(input_arr, len(input_arr))
for value in output_arr:
    print(value)
print("Number of prints: " + str(len(output_arr)))
