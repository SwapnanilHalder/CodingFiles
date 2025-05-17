from collections import deque

def lex_min_path(n, grid):
    visited = [[False] * n for _ in range(n)]
    queue = deque()
    queue.append((0, 0))
    visited[0][0] = True
    result = grid[0][0]

    for _ in range(2 * n - 2):  # There are 2n - 1 cells in the path
        next_positions = []
        min_char = '{'  # higher than any uppercase letter

        for _ in range(len(queue)):
            x, y = queue.popleft()
            for dx, dy in [(0, 1), (1, 0)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny]:
                    visited[nx][ny] = True
                    next_positions.append((nx, ny))
                    if grid[nx][ny] < min_char:
                        min_char = grid[nx][ny]

        # Filter only positions with the minimum character
        queue.extend((x, y) for (x, y) in next_positions if grid[x][y] == min_char)
        result += min_char

    return result

# Read input
n = int(input())
grid = [input().strip() for _ in range(n)]
print(lex_min_path(n, grid))