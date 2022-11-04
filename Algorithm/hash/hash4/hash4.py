import time

class HashTable:
    # your code is here
    # ----------------------------------------------
    # ----------------------------------------------

def constructHash(m):
    # your code is here
    # ----------------------------------------------
    # ----------------------------------------------


def insertHash(hashtable, key):
    # your code is here
    # ----------------------------------------------
    # ----------------------------------------------

def deleteHash(hashtable, key):
    # your code is here
    # ----------------------------------------------
    # ----------------------------------------------

def searchHash(hashtable, key):
    # your code is here
    # ----------------------------------------------
    # ----------------------------------------------

def compare_output(file1, file2):
    f1 = open(file1, "r")
    f2 = open(file2, "r")

    lines1 = f1.readlines()
    lines2 = f2.readlines()

    success = True
    i = 0
    for _ in lines2:
        if lines1[i].strip() != lines2[i].strip():
            print("[%i] Wrong answer: Yours=\'%s\', Expected=\'%s\'\n" % (i+1, lines1[i].strip(), lines2[i].strip()))
            success = False
            break
        i = i + 1

    if success:
        print("Success!")
    f1.close()
    f2.close()


# main code
input = open("input_data.txt", "r")      # input data
output = open("output_data.txt", "w")    # your answer

start_time = time.time()

hashtable = constructHash(541)

for _ in range(400):
    line = input.readline().split()
    key  = int(line[0])
    result = insertHash(hashtable, key)
    if result == 1:
        output.write('Success\n')
    else:
        output.write('Collision\n')

for _ in range(200):
    line = input.readline().split()
    key  = int(line[0])
    result = deleteHash(hashtable, key)
    if result == 1:
        output.write('Success\n')
    else:
        output.write('Fail\n')

for _ in range(200):
    line = input.readline().split()
    key  = int(line[0])
    result = searchHash(hashtable, key)
    if result == 1:
        output.write('Success\n')
    else:
        output.write('Fail\n')

end_time = time.time()
## -----------------------------------------------
    
# DO NOT EDIT. Checking answers
input.close()
output.close()
print('Elapsed time: {:.2f} seconds. '.format(end_time - start_time), end='')
compare_output("output_data.txt", "expected_data.txt")
