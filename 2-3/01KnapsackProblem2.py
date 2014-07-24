#coding: UTF-8

MAX_N = 100
MAX_W = 10000

n =4
W = 5
w = [2, 1, 3, 2]
v = [3, 2, 4, 2]

# メモ化テーブル
dp = [[-1 for j in range(MAX_W+1)] for i in range(MAX_N)]

# i番目以降の品物から重さの総和がj以下になるように選ぶ
def rec(i, j):
    # 調べたことがある場合はテーブルの値を返す
    if dp[i][j] >= 0:
        return dp[i][j]
    
    if i == n:
        # all item is evaluated
        res = 0
    elif(j < w[i]):
        # i番目の品物は入らない
        res = rec(i + 1, j)
    else:
        # 入れる場合、入れない場合のうち価値が高い方を選択
        res = max(rec(i + 1, j), rec(i + 1, j - w[i]) + v[i])
    dp[i][j] = res
    return res

def solve():
    print "the answer is " + str(rec(0, W))


solve()
