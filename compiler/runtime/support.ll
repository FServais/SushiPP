; ModuleID = 'runtime/support.c'
target datalayout = "e-m:o-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx10.10.0"

@.str = private unnamed_addr constant [4 x i8] c"%ld\00", align 1
@.str1 = private unnamed_addr constant [3 x i8] c"%f\00", align 1
@.str3 = private unnamed_addr constant [3 x i8] c"%s\00", align 1
@.str4 = private unnamed_addr constant [5 x i8] c"true\00", align 1
@.str5 = private unnamed_addr constant [6 x i8] c"false\00", align 1
@.str6 = private unnamed_addr constant [5 x i8] c"%ld\0A\00", align 1
@.str7 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str8 = private unnamed_addr constant [4 x i8] c"%c\0A\00", align 1

; Function Attrs: nounwind ssp uwtable
define void @print_int(i64 %val) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str, i64 0, i64 0), i64 %val) #3
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture readonly, ...) #1

; Function Attrs: nounwind ssp uwtable
define void @print_float(float %val) #0 {
  %1 = fpext float %val to double
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str1, i64 0, i64 0), double %1) #3
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @print_char(i8 signext %val) #0 {
  %1 = sext i8 %val to i32
  %putchar = tail call i32 @putchar(i32 %1) #3
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @print_bool(i1 zeroext %val) #0 {
  %1 = select i1 %val, i8* getelementptr inbounds ([5 x i8]* @.str4, i64 0, i64 0), i8* getelementptr inbounds ([6 x i8]* @.str5, i64 0, i64 0)
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str3, i64 0, i64 0), i8* %1) #3
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @println_int(i64 %val) #0 {
  %1 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @.str6, i64 0, i64 0), i64 %val) #3
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @println_float(float %val) #0 {
  %1 = fpext float %val to double
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str7, i64 0, i64 0), double %1) #3
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @println_char(i8 signext %val) #0 {
  %1 = sext i8 %val to i32
  %2 = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str8, i64 0, i64 0), i32 %1) #3
  ret void
}

; Function Attrs: nounwind ssp uwtable
define void @println_bool(i1 zeroext %val) #0 {
  %1 = select i1 %val, i8* getelementptr inbounds ([5 x i8]* @.str4, i64 0, i64 0), i8* getelementptr inbounds ([6 x i8]* @.str5, i64 0, i64 0)
  %puts = tail call i32 @puts(i8* %1)
  ret void
}

; Function Attrs: nounwind readnone ssp uwtable
define i32 @pow_int(i64 %base, i64 %exp) #2 {
  br label %tailrecurse

tailrecurse:                                      ; preds = %12, %0
  %base.tr = phi i64 [ %base, %0 ], [ %13, %12 ]
  %exp.tr = phi i64 [ %exp, %0 ], [ %14, %12 ]
  switch i64 %exp.tr, label %3 [
    i64 0, label %.loopexit.loopexit
    i64 1, label %1
  ]

; <label>:1                                       ; preds = %tailrecurse
  %base.tr.lcssa13 = phi i64 [ %base.tr, %tailrecurse ]
  %2 = trunc i64 %base.tr.lcssa13 to i32
  br label %.loopexit

; <label>:3                                       ; preds = %tailrecurse
  %4 = and i64 %exp.tr, 1
  %5 = icmp eq i64 %4, 0
  br i1 %5, label %12, label %6

; <label>:6                                       ; preds = %3
  %exp.tr.lcssa16 = phi i64 [ %exp.tr, %3 ]
  %base.tr.lcssa14 = phi i64 [ %base.tr, %3 ]
  %7 = add i64 %exp.tr.lcssa16, -1
  %8 = tail call i32 @pow_int(i64 %base.tr.lcssa14, i64 %7)
  %9 = sext i32 %8 to i64
  %10 = mul i64 %9, %base.tr.lcssa14
  %11 = trunc i64 %10 to i32
  ret i32 %11

; <label>:12                                      ; preds = %3
  %13 = mul i64 %base.tr, %base.tr
  %14 = lshr i64 %exp.tr, 1
  br label %tailrecurse

.loopexit.loopexit:                               ; preds = %tailrecurse
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %1
  %.0 = phi i32 [ %2, %1 ], [ 1, %.loopexit.loopexit ]
  ret i32 %.0
}

; Function Attrs: nounwind readnone ssp uwtable
define float @pow_float(float %base, i64 %exp) #2 {
  br label %tailrecurse

tailrecurse:                                      ; preds = %8, %0
  %base.tr = phi float [ %base, %0 ], [ %9, %8 ]
  %exp.tr = phi i64 [ %exp, %0 ], [ %10, %8 ]
  switch i64 %exp.tr, label %1 [
    i64 0, label %.loopexit.loopexit
    i64 1, label %.loopexit9
  ]

; <label>:1                                       ; preds = %tailrecurse
  %2 = and i64 %exp.tr, 1
  %3 = icmp eq i64 %2, 0
  br i1 %3, label %8, label %4

; <label>:4                                       ; preds = %1
  %exp.tr.lcssa17 = phi i64 [ %exp.tr, %1 ]
  %base.tr.lcssa15 = phi float [ %base.tr, %1 ]
  %5 = add i64 %exp.tr.lcssa17, -1
  %6 = tail call float @pow_float(float %base.tr.lcssa15, i64 %5)
  %7 = fmul float %base.tr.lcssa15, %6
  ret float %7

; <label>:8                                       ; preds = %1
  %9 = fmul float %base.tr, %base.tr
  %10 = lshr i64 %exp.tr, 1
  br label %tailrecurse

.loopexit9:                                       ; preds = %tailrecurse
  %base.tr.lcssa14 = phi float [ %base.tr, %tailrecurse ]
  br label %.loopexit

.loopexit.loopexit:                               ; preds = %tailrecurse
  br label %.loopexit

.loopexit:                                        ; preds = %.loopexit.loopexit, %.loopexit9
  %.0 = phi float [ %base.tr.lcssa14, %.loopexit9 ], [ 1.000000e+00, %.loopexit.loopexit ]
  ret float %.0
}

; Function Attrs: nounwind
declare i32 @putchar(i32) #3

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture readonly) #3

attributes #0 = { nounwind ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone ssp uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Apple LLVM version 6.1.0 (clang-602.0.49) (based on LLVM 3.6.0svn)"}
