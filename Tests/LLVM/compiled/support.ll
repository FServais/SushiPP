; ModuleID = 'support.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [5 x i8] c"%ld\0A\00", align 1
@.str1 = private unnamed_addr constant [4 x i8] c"%f\0A\00", align 1
@.str2 = private unnamed_addr constant [4 x i8] c"%c\0A\00", align 1
@.str3 = private unnamed_addr constant [4 x i8] c"%s\0A\00", align 1
@.str4 = private unnamed_addr constant [5 x i8] c"true\00", align 1
@.str5 = private unnamed_addr constant [6 x i8] c"false\00", align 1
@.str6 = private unnamed_addr constant [17 x i8] c"String id : %zu\0A\00", align 1

; Function Attrs: nounwind uwtable
define void @print_int(i64 %val) #0 {
entry:
  %val.addr = alloca i64, align 8
  store i64 %val, i64* %val.addr, align 8
  %0 = load i64* %val.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([5 x i8]* @.str, i32 0, i32 0), i64 %0)
  ret void
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind uwtable
define void @print_float(float %val) #0 {
entry:
  %val.addr = alloca float, align 4
  store float %val, float* %val.addr, align 4
  %0 = load float* %val.addr, align 4
  %conv = fpext float %0 to double
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), double %conv)
  ret void
}

; Function Attrs: nounwind uwtable
define void @print_char(i8 signext %val) #0 {
entry:
  %val.addr = alloca i8, align 1
  store i8 %val, i8* %val.addr, align 1
  %0 = load i8* %val.addr, align 1
  %conv = sext i8 %0 to i32
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str2, i32 0, i32 0), i32 %conv)
  ret void
}

; Function Attrs: nounwind uwtable
define void @print_bool(i1 zeroext %val) #0 {
entry:
  %val.addr = alloca i8, align 1
  %frombool = zext i1 %val to i8
  store i8 %frombool, i8* %val.addr, align 1
  %0 = load i8* %val.addr, align 1
  %tobool = trunc i8 %0 to i1
  %cond = select i1 %tobool, i8* getelementptr inbounds ([5 x i8]* @.str4, i32 0, i32 0), i8* getelementptr inbounds ([6 x i8]* @.str5, i32 0, i32 0)
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str3, i32 0, i32 0), i8* %cond)
  ret void
}

; Function Attrs: nounwind uwtable
define void @print_string(i64 %string_id) #0 {
entry:
  %string_id.addr = alloca i64, align 8
  store i64 %string_id, i64* %string_id.addr, align 8
  %0 = load i64* %string_id.addr, align 8
  %call = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([17 x i8]* @.str6, i32 0, i32 0), i64 %0)
  ret void
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
