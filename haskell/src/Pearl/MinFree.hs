module Pearl.MinFree
  (minfree
  ) where

minfree :: [Integer] -> Integer
minfree xs = head ([0 ..] \\ xs)
  where
    (\\) :: Eq a => [a] -> [a] -> [a]
    us \\ vs = filter (fn vs) us

    fn :: Eq a => [a] -> a -> Bool
    fn vs x = notElem x vs

