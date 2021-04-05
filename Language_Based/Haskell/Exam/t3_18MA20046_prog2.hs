-- Swapnanil Halder
-- 18MA20046

data Btree a = Empty | Node (Btree a) a (Btree a)

-- Function to just print the head of a node
print_head :: Btree Int -> [Int]
print_head Empty = []
print_head (Node lt x rt) = [x]

-- at the very start, we add the main head in the array using a special notation in passing arguments ( the first argument, if 0, this is the main head, if 1, we are inside the BTree)
-- Then, we first add the lefts and rights in the array using print_head, and then pass the lefts and rights as new head using recursion
leftTop_bottomRight :: Int-> Btree Int -> [Int]
leftTop_bottomRight _ Empty = []
leftTop_bottomRight _ (Node Empty x Empty) = []
leftTop_bottomRight e (Node lt x rt) = 
    if e == 0 then [x] ++ (leftTop_bottomRight 1 (Node lt x rt))
    else (print_head lt) ++ (print_head rt) ++ (leftTop_bottomRight 1 lt) ++ (leftTop_bottomRight 1 rt)

main = do
    let t2 = Node (Node (Node Empty 7 Empty) 5 (Node Empty 3 Empty)) 6 (Node (Node Empty 9 Empty) 4 Empty)
    print $ leftTop_bottomRight 0 t2