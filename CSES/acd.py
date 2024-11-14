def min_difference(arr, n):
    """
    Finds the minimum difference between two subsets of the given array.

    Args:
        arr: The array of apple weights.
        n: The number of apples.

    Returns:
        The minimum difference.
    """

    total_sum = sum(arr)
    dp = [[False for x in range(total_sum + 1)] for x in range(n + 1)]

    # Initialize the DP table
    for i in range(n + 1):
        dp[i][0] = True

    for i in range(1, total_sum + 1):
        dp[0][i] = False

    # Fill the DP table
    for i in range(1, n + 1):
        for j in range(1, total_sum + 1):
            if arr[i - 1] <= j:
                dp[i][j] = dp[i - 1][j - arr[i - 1]] or dp[i - 1][j]
            else:
                dp[i][j] = dp[i - 1][j]

    # Find the subset sum closest to half the total sum
    diff = total_sum
    for i in range(total_sum // 2 + 1):
        if dp[n][i] == True:
            diff = min(diff, total_sum - 2 * i)

    return diff

# Example usage:
apple_weights = [314836307, 815098885 ,922742346 ,53006071 ,757943472, 481505203 ,354207278 ,175676232, 335088325, 921705085 ,231986392, 619406418, 170606376 ,498080884, 415616625, 40905556, 110076295 ,642911923, 932231564, 381545587]
n = len(apple_weights)
min_diff = min_difference(apple_weights, n)
print("Minimum difference:", min_diff)