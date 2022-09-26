#-----------------------------------------------------------------------
'''
N개의 행렬을 곱할 때 최소의 곱셈 수를 구하는 문제

N개의 행렬에 대해 p0, p1, p2, p3, ..., pN의 행렬의 크기가 주엊니다.
첫 번째 행렬의 크기는 p0p1이며 두 번째 행렬의 크기는 p1p2, 마지막 행렬의 크기는 pN-1 pN이다.
N개의 행렬을 곱하고자 한다. 행렬의 요소끼리 곱해지는 곱셈 횟수의 최소값을 구하시오.

입력 file 형식
K     // 행렬 곱셈의 입력 수
N p0 p1 p2 p3 p4 ....   // 첫번 째 행렬 곱셈을 위한 행렬의 크기 정보
N p0 p1 p2 p3 p4 ....   // 두번 째 행렬 곱셈을 위한 행렬의 크기 정보
N p0 p1 p2 p3 p4 ....   // 세번 째 행렬 곱셈을 위한 행렬의 크기 정보
:
:

조건:
1. p_k의 최대 값은 100이다.

예시)
입력: input_matmul.txt
3
4 10 20 30 40 50
3 50 60 70 80
7 4 5 6 7 6 5 4 2

출력: output_matmul.txt
38000
490000
368

정답은 expected_matmul.txt로 주어짐
결과는 output_matmul.txt file로 출력해야 함

Dynamic programming 기법을 이용해서 아래 코드의 matmul 함수를 완성하시오.
'''
#-----------------------------------------------------------------------

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


def matmul(p):
    # your code is here
    # ----------------------------------------------
    n=len(p)
    m=[[0]*(n+1) for _ in range(n+1)]
    for i in range(1,n):
        m[i][i]=0
    for r in range(1,n):
        for i in range(1,n-r):
            j=i+r
            m[i][j]=m[i][i]+m[i+1][j]+(p[i-1]*p[i]*p[j])
            for k in range(i+1,j): #i부터(i+1) j-1까지(j)
                if m[i][j]>m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j]):
                    m[i][j]=m[i][k]+m[k+1][j]+(p[i-1]*p[k]*p[j])

    return m[1][n-1]
    # ----------------------------------------------


# main code
input = open("input_matmul.txt", "r")      # input data
output = open("output_matmul.txt", "w")    # your answer

nums = input.readline().split()
K = int(nums[0])
for _ in range(K):
    nums = input.readline().split()
    p = [0]*(int(nums[0]) + 1)
    for i in range(int(nums[0]) + 1):
        p[i] = int(nums[i + 1])
    min_multiplications = matmul(p)
    output.write("{}\n".format(min_multiplications))
    ## -----------------------------------------------

# DO NOT EDIT. Checking answers
input.close()
output.close()
compare_output("output_matmul.txt", "expected_matmul.txt")
