module Pearl.MinFreeSpec where

import Control.Monad
import Test.Hspec
import Text.Printf

import Pearl.MinFree

main :: IO ()
main = hspec spec

spec :: Spec
spec = do
  forM_ cases $ \(a, expected) ->
    it (printf "minfree %v shouldBe %v" (show a) expected) $
      minfree a `shouldBe` expected
  where
    cases :: [([Integer], Integer)]
    cases = [
        ([], 0),
        ([1,2,3], 0),
        ([0,1,2,4,5], 3)
      ]

