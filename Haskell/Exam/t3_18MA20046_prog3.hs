-- Swapnanil Halder
-- 18MA20046

data Nat = Zero | Succ Nat -- non negative integers

add :: Nat -> Nat -> Nat 
add m Zero = m 
add m (Succ (n)) = Succ (add m n)

-- Here we are multiplying using addition in recursive manner
multiplication :: Nat -> Nat -> Nat 
multiplication m Zero = Zero
multiplication m (Succ n) = add m (multiplication m n)  -- m ( n + 1) = m + m*n


convtoint :: Nat -> Int -- convert to int
convtoint Zero = 0  -- converts Zero (which is user defined) to actual 0
convtoint (Succ n) = 1 + (convtoint n) 


main = do
    print $ [5..13]
