#잃어버린 괄호

N = [x for x in input().split(sep='-')]

result = sum(map(int, N[0].split(sep="+")))

for x in N[1:]:
    result -= sum(map(int, x.split(sep="+")))

print(result)
