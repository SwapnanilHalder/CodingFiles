fac :: (Ord t, Num t) => t ->  t
fac n = aux n 1
    where
        aux n acc
            | n <= 1 = acc
            | otherwise = aux (n-1) (n * acc)

evens :: [Int] -> [Int]
evens [] = []
evens (x:xs)
    |   x `mod` 2 == 0 = x : evens xs
    |   otherwise = evens xs

elem_in :: (Eq a) => a -> [a] -> Bool
elem_in _ [] = False
elem_in a (x:xs)
    | x == a = True
    | otherwise = elem_in a xs

elemIn :: (Eq a) => a->[a]-> Bool
elemIn _ [] = False
elemIn e (x:xs) = (e == x) || (elemIn e xs)

remove_duplicate :: (Eq a) => [a] -> [a]
remove_duplicate [] = []
remove_duplicate (x:xs)
    |   x `elem_in` xs = remove_duplicate xs
    |   otherwise      = x : remove_duplicate xs

isAsc :: [Int] -> Bool
isAsc [] = True
isAsc [_] = True
isAsc (x:xs)
    |   x <= head xs = isAsc xs
    |   otherwise = False

reverse_foldl :: [a] -> [a]
reverse_foldl = foldl (\acc x -> x : acc) []

reverse_foldr :: [a] -> [a]
reverse_foldr = foldr (\acc x -> acc : x) []

main :: IO ()
main = do
    print $ fac 6
    print $ evens [5..103]
    print $ elem_in 10 [ 3..9]
    print $ elemIn 10 [5..15]
    print $ remove_duplicate [1,2,3,1,2,4,9,8,5,2, 6,4,5]
    print $ isAsc [1,5,9,12,15,39,22,25,29]
    print $ foldr (+) 0 [1..10] 
    print $ Main.reverse_foldl [1..10]
    print $ reverse_foldr [1..5]
    print $  (\a -> (head.reverse) a) [5..12]
    print $  (\a -> (head.tail.reverse) a) [5..12]
    print $ init [6..13]
    -- print $ (\a -> foldl (flip (:)) [] ) [5..15]
    