; ModuleID = 'support.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [5 x i8] c"%ld\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%c\0A\00", align 1
@.str4 = private unnamed_addr constant [5 x i8] c"true\00", align 1
@.str5 = private unnamed_addr constant [6 x i8] c"false\00", align 1
@.str6 = private unnamed_addr constant [17 x i8] c"String id : %zu\0A\00", align 1

; Function Attrs: nounwind uwtable
define void @print_int(i64 %val) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @.str, i64 0, i64 0), i64 %val) #3
  ret void
}

; Function Attrs: nounwind
declare i32 @printf(i8* nocapture, ...) #1

; Function Attrs: nounwind uwtable
define void @print_float(float %val) #0 {
entry:
  %conv = fpext float %val to double
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i64 0, i64 0), double %conv) #3
  ret void
}

; Function Attrs: nounwind uwtable
define void @print_char(i8 signext %val) #0 {
entry:
  %conv = sext i8 %val to i32
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i64 0, i64 0), i32 %conv) #3
  ret void
}

; Function Attrs: nounwind uwtable
define void @print_bool(i1 zeroext %val) #0 {
entry:
  %cond = select i1 %val, i8* getelementptr inbounds ([5 x i8]* @.str4, i64 0, i64 0), i8* getelementptr inbounds ([6 x i8]* @.str5, i64 0, i64 0)
  %puts = tail call i32 @puts(i8* %cond)
  ret void
}

; Function Attrs: nounwind uwtable
define void @print_string(i64 %string_id) #0 {
entry:
  %call = tail call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @.str6, i64 0, i64 0), i64 %string_id) #3
  ret void
}

; Function Attrs: nounwind readnone uwtable
define i32 @pow_int(i64 %base, i64 %exp) #2 {
entry:
  br label %tailrecurse

tailrecurse:                                      ; preds = %if.end7, %entry
  %base.tr = phi i64 [ %base, %entry ], [ %mul8, %if.end7 ]
  %exp.tr = phi i64 [ %exp, %entry ], [ %div, %if.end7 ]
  switch i64 %exp.tr, label %if.end3 [
    i64 0, label %return
    i64 1, label %if.then2
  ]

if.then2:                                         ; preds = %tailrecurse
  %conv = trunc i64 %base.tr to i32
  br label %return

if.end3:                                          ; preds = %tailrecurse
  %rem = and i64 %exp.tr, 1
  %tobool = icmp eq i64 %rem, 0
  br i1 %tobool, label %if.end7, label %if.then4

if.then4:                                         ; preds = %if.end3
  %sub = add i64 %exp.tr, -1
  %call = tail call i32 @pow_int(i64 %base.tr, i64 %sub)
  %conv5 = sext i32 %call to i64
  %mul = mul i64 %conv5, %base.tr
  %conv6 = trunc i64 %mul to i32
  ret i32 %conv6

if.end7:                                          ; preds = %if.end3
  %mul8 = mul i64 %base.tr, %base.tr
  %div = lshr i64 %exp.tr, 1
  br label %tailrecurse

return:                                           ; preds = %tailrecurse, %if.then2
  %retval.0 = phi i32 [ %conv, %if.then2 ], [ 1, %tailrecurse ]
  ret i32 %retval.0
}

; Function Attrs: nounwind readnone uwtable
define float @pow_float(float %base, i64 %exp) #2 {
entry:
  br label %tailrecurse

tailrecurse:                                      ; preds = %if.end5, %entry
  %base.tr = phi float [ %base, %entry ], [ %mul6, %if.end5 ]
  %exp.tr = phi i64 [ %exp, %entry ], [ %div, %if.end5 ]
  switch i64 %exp.tr, label %if.end3 [
    i64 0, label %return.loopexit
    i64 1, label %return
  ]

if.end3:                                          ; preds = %tailrecurse
  %rem = and i64 %exp.tr, 1
  %tobool = icmp eq i64 %rem, 0
  br i1 %tobool, label %if.end5, label %if.then4

if.then4:                                         ; preds = %if.end3
  %sub = add i64 %exp.tr, -1
  %call = tail call float @pow_float(float %base.tr, i64 %sub)
  %mul = fmul float %base.tr, %call
  ret float %mul

if.end5:                                          ; preds = %if.end3
  %mul6 = fmul float %base.tr, %base.tr
  %div = lshr i64 %exp.tr, 1
  br label %tailrecurse

return.loopexit:                                  ; preds = %tailrecurse
  br label %return

return:                                           ; preds = %tailrecurse, %return.loopexit
  %retval.0 = phi float [ 1.000000e+00, %return.loopexit ], [ %base.tr, %tailrecurse ]
  ret float %retval.0
}

; Function Attrs: nounwind
declare i32 @puts(i8* nocapture) #3

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { nounwind readnone uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind }
