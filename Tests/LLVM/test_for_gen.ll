; ModuleID = 'test_for_gen.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128" 
target triple = "x86_64-apple-macosx10.10.0"

@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1
declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind ssp uwtable
define i32 @main(i32 %ac, i8** %av) #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i8**, align 8
  %i = alloca i32, align 4
  %j = alloca i32, align 4
  %k = alloca i32, align 4
  %p = alloca i32, align 4
  store i32 0, i32* %1
  store i32 %ac, i32* %2, align 4
  store i8** %av, i8*** %3, align 8
  store i32 0, i32* %i, align 4
  store i32 2, i32* %j, align 4
  store i32 3, i32* %k, align 4
  %4 = load i32* %k, align 4
  %5 = load i32* %i, align 4
  %6 = add nsw i32 %4, %5
  %7 = load i32* %j, align 4
  %8 = add nsw i32 %6, %7
  store i32 %8, i32* %p, align 4
  %9 = load i32* %i, align 4
  %10 = icmp sgt i32 %9, 2
  br i1 %10, label %11, label %13

; <label>:11                                      ; preds = %0
  %12 = load i32* %k, align 4
  store i32 %12, i32* %p, align 4
  br label %13

; <label>:13                                      ; preds = %11, %0
  %14 = load i32* %p, align 4
  %15 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %14)
  %16 = load i32* %1
  ret i32 %16
}

; Function Attrs: nounwind ssp uwtable
define i32 @func(i32 %argument) #0 {
  %1 = alloca i32, align 4
  %temp = alloca i32, align 4
  store i32 %argument, i32* %1, align 4
  %2 = load i32* %1, align 4
  %3 = add nsw i32 %2, 1
  store i32 %3, i32* %temp, align 4
  %4 = load i32* %temp, align 4
  ret i32 %4
}

attributes #0 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Apple LLVM version 6.1.0 (clang-602.0.49) (based on LLVM 3.6.0svn)"}
