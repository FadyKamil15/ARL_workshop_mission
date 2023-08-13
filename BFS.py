import queue
import numpy as np

grid = np.array([[0,0,1,0,0],
                [0,0,1,0,0],
                [0,0,1,0,0],
                [0,0,0,0,0],
                [0,0,0,0,0]])
start_i = 1
start_j = 1
goal_i = 4
goal_j = 1
my_queue = queue.Queue()
my_queue.put('')

def transform (start_i, start_j, path):
    new_i = start_i
    new_j = start_j
    for i in range(len(path)):
        if path[i] == 'l':
            new_i -= 1
        if path[i] == 'u':
            new_j -= 1
        if path[i] == 'd':
            new_j += 1
        if path[i] == 'r':
            new_i += 1
    return new_i, new_j

def goal(current_i, current_j):
    if current_i == goal_i and current_j == goal_j:
        return True

while (True):
    current_path = my_queue.get()
    i,j = transform(start_i, start_j, current_path)
    
    if (goal(i,j) == 1):
        break

    #generating possible paths (neighbours)
    if(i<4 and grid[j][i+1] != 1) :
        new_path = current_path + 'r'
        grid[j][i+1] = 1
        my_queue.put(new_path)
    if(i>0 and grid[j][i-1] != 1):
        new_path = current_path + 'l'
        grid[j][i-1] = 1
        my_queue.put(new_path)
    if(j>0 and grid[j-1][i] != 1):
        new_path = current_path + 'u'
        grid[j-1][i] = 1
        my_queue.put(new_path)
    if(j<4 and grid[j+1][i] != 1):
        new_path = current_path + 'd'
        grid[j+1][i] = 1
        my_queue.put(new_path)
    

print(current_path)

            
