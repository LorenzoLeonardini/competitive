c = ['Y Y Y Y Y Y N',
'N Y Y N N N N',
'Y Y N Y Y N Y',
'Y Y Y Y N N Y',
'N Y Y N N Y Y',
'Y N Y Y N Y Y',
'Y N Y Y Y Y Y',
'Y Y Y N N N N',
'Y Y Y Y Y Y Y',
'Y Y Y Y N Y Y']

for num in c:
    a = ''
    for i in range(0, 7):
        if num.split(' ')[7 - 1 - i] == 'Y':
            a += '1'
        else:
            a += '0'
    print(int(a, 2), end=', ')
