; ModuleID = 'test_for_gen.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.10.0"

; Function Attrs: nounwind ssp uwtable
define i32 @main(i32 %ac, i8** %av) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i8**, align 8
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  store i32 %ac, i32* %1, align 4
  store i8** %av, i8*** %2, align 8
  store i32 0, i32* %i, align 4
  store i32 2, i32* %j, align 4
  store i32 3, i32* %k, align 4
  %3 = load i32* %i, align 4
  %4 = load i32* %j, align 4
  %5 = load i32* %k, align 4
  %6 = mul nsw i32 %4, %5
  %7 = add nsw i32 %3, %6
  store i32 %7, i32* %k, align 4
  %8 = load i32* %i, align 4
  %9 = load i32* %j, align 4
  %10 = call i32 @func(i32 %8, i32 %9)
  ret i32 0
}

; Function Attrs: nounwind ssp uwtable
define i32 @func(i32 %a, i32 %b) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  store i32 %a, i32* %1, align 4
  store i32 %b, i32* %2, align 4
  %3 = load i32* %1, align 4
  %4 = load i32* %2, align 4
  %5 = add nsw i32 %3, %4
  ret i32 %5
}

attributes #0 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Apple LLVM version 6.1.0 (clang-602.0.49) (based on LLVM 3.6.0svn)"}
