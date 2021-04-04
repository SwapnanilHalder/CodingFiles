-- Swapnanil Halder
-- 18MA20046

data Nat = Zero | Succ Nat -- non negative integers

data Inti = Pos Nat | Neg Nat  -- Extending Natural DataType to accommodate Integer type operations(Addition, Subtraction, Multiplication and Convert to Int) on integer numbers

-- plus function adds two numbers, it takes inputs in Nat format and also outputs in Nat format
plus :: Nat -> Nat -> Nat 
plus m Zero = m 
plus m (Succ (n)) = Succ (plus m n)

-- Subtracts two numbers
subt :: Nat->Nat->Nat
subt m Zero = m
subt (Succ m) (Succ n) = subt m n

-- plusint sends two suitable IntI formatted inputs in plus or subt in Natural form
plusint :: Inti -> Inti -> Inti  
plusint (Neg m) (Neg n) = Neg(plus m n)  
plusint (Pos m) (Pos n) = Pos(plus m n)
plusint (Pos m) (Neg n)
    | convtoint(m)>=convtoint(n) = Pos(subt m n)
    | otherwise= Neg(subt n m) 
plusint (Neg m) (Pos n)
    | convtoint(n)>=convtoint(m) = Pos(subt n m)
    | otherwise= Neg(subt m n) 

-- subtint sends two suitable IntI formatted inputs in plusint function in positive or negative version(whichever necessary)
subtint :: Inti->Inti->Inti
subtint m (Pos n) = (plusint m (Neg n))
subtint m (Neg n) = (plusint m (Pos n))

-- Converts Nat type Datas into Int
convtoint :: Nat -> Int -- convert to int
convtoint Zero = 0  -- converts Zero (which is user defined) to actual 0
convtoint (Succ n) = 1 + (convtoint n)

-- Convert converts Inti type datas into Int using convtoint function
convert :: Inti -> Int 
convert (Neg n) = (-1)*(convtoint n)
convert (Pos n) = convtoint n

-- multint function recursively uses addition and subtraction functions to get desired result
multint :: Inti -> Inti -> Inti
multint (Pos m) (Pos Zero) = (Pos Zero)
multint (Neg m) (Pos Zero) = (Pos Zero)
multint (Pos m) (Pos n) = plusint (Pos m) (multint (Pos m) (subtint (Pos n) (Pos (Succ Zero))) )  
multint (Pos m) (Neg n) = subtint (Pos Zero) (plusint (Pos m) (multint (Pos m) (subtint (Pos n) (Pos (Succ Zero))) ) )  
multint (Neg m) (Neg n) = plusint (Pos m) (multint (Pos m) (subtint (Pos n) (Pos (Succ Zero))) )  
multint (Neg m) (Pos n) = subtint (Pos Zero) (plusint (Pos m) (multint (Pos m) (subtint (Pos n) (Pos (Succ Zero))) ) )  

main :: IO ()
main = do
    let n1 = Pos(Succ (Succ Zero) )  -- 2
    let n2 = Neg(Succ (Succ (Succ(Succ(Succ Zero) ))))--  -5
    let zeroed = Pos(Zero)
    let n3 = Pos(Succ (Succ (Succ(Succ(Succ Zero) ))))
    print $ convert (plusint n1 n2)
    print $ convert (subtint n1 n2)
    print $ convert (multint n1 n2)
    print $ convert (multint n2 n1)
    print $ convert (multint n2 n3)
    print $ convert (multint n2 zeroed )