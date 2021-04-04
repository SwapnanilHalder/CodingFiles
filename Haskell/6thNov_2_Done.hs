addLists :: [[Integer]] -> [Integer]
addLists [] = []
-- concating x and recursive breaking down the inner brackets of rest of the list
addLists (x:xs) = x ++ addLists xs

main = do
    let a = [[1,2,3], [7,6,8], [0,3,4], [7,8]]
    print $ addLists a