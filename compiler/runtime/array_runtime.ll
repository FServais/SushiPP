; ModuleID = 'array_runtime.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%struct.array_table = type { %struct.array_descriptor* }
%struct.array_descriptor = type { i64, i64, i64, i8*, i64, %struct.array_descriptor* }

@stderr = external global %struct._IO_FILE*
@.str = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `create_array_table`\0A\00", align 1
@.str1 = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `array_remove_value`\0A\00", align 1
@bytes_per_type = internal unnamed_addr constant [5 x i64] [i64 4, i64 4, i64 1, i64 1, i64 8], align 16
@.str2 = private unnamed_addr constant [51 x i8] c"Memory allocation failure in `array_insert_value`\0A\00", align 1
@.str3 = private unnamed_addr constant [53 x i8] c"Memory allocation failure in `new_array_descriptor`\0A\00", align 1
@array_counter = internal unnamed_addr global i64 1, align 8

; Function Attrs: nounwind uwtable
define i64 @array_allocate_int(%struct.array_table* %table, i64 %size, i32* nocapture %populate) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @array_counter, align 8, !tbaa !0
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @array_counter, align 8, !tbaa !0
  %call1 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %0, i64 %size, i64 0)
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %1 = load %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %next.i = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 5
  store %struct.array_descriptor* %1, %struct.array_descriptor** %next.i, align 8, !tbaa !3
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 3
  %2 = load i8** %array_ptr, align 8, !tbaa !3
  %3 = bitcast i32* %populate to i8*
  %mul = shl i64 %size, 2
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* %3, i64 %mul, i32 1, i1 false)
  br label %return

return:                                           ; preds = %entry, %if.end
  %retval.0 = phi i64 [ %0, %if.end ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define internal fastcc noalias %struct.array_descriptor* @new_array_descriptor(i64 %id, i64 %size, i64 %type) #0 {
entry:
  %call = tail call noalias i8* @malloc(i64 48) #1
  %0 = bitcast i8* %call to %struct.array_descriptor*
  %tobool = icmp eq i8* %call, null
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str3, i64 0, i64 0), i64 52, i64 1, %struct._IO_FILE* %1)
  tail call void @exit(i32 1) #5
  unreachable

if.end:                                           ; preds = %entry
  %array_id = bitcast i8* %call to i64*
  store i64 %id, i64* %array_id, align 8, !tbaa !0
  %array_size = getelementptr inbounds i8* %call, i64 8
  %3 = bitcast i8* %array_size to i64*
  store i64 %size, i64* %3, align 8, !tbaa !0
  %ref_count2 = getelementptr inbounds i8* %call, i64 32
  %4 = bitcast i8* %ref_count2 to i64*
  store i64 0, i64* %4, align 8, !tbaa !0
  %type3 = getelementptr inbounds i8* %call, i64 16
  %5 = bitcast i8* %type3 to i64*
  store i64 %type, i64* %5, align 8, !tbaa !0
  %next = getelementptr inbounds i8* %call, i64 40
  %6 = bitcast i8* %next to %struct.array_descriptor**
  store %struct.array_descriptor* null, %struct.array_descriptor** %6, align 8, !tbaa !3
  %cmp = icmp eq i64 %size, 0
  br i1 %cmp, label %cond.end.thread, label %cond.end

cond.end.thread:                                  ; preds = %if.end
  %array_ptr1 = getelementptr inbounds i8* %call, i64 24
  %7 = bitcast i8* %array_ptr1 to i8**
  store i8* null, i8** %7, align 8, !tbaa !3
  br label %if.end11

cond.end:                                         ; preds = %if.end
  %arrayidx.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %type
  %8 = load i64* %arrayidx.i, align 8, !tbaa !0
  %mul = mul i64 %8, %size
  %call5 = tail call noalias i8* @malloc(i64 %mul) #1
  %array_ptr = getelementptr inbounds i8* %call, i64 24
  %9 = bitcast i8* %array_ptr to i8**
  store i8* %call5, i8** %9, align 8, !tbaa !3
  %tobool8 = icmp eq i8* %call5, null
  br i1 %tobool8, label %if.then9, label %if.end11

if.then9:                                         ; preds = %cond.end
  %10 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %11 = tail call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str3, i64 0, i64 0), i64 52, i64 1, %struct._IO_FILE* %10)
  tail call void @exit(i32 1) #5
  unreachable

if.end11:                                         ; preds = %cond.end.thread, %cond.end
  ret %struct.array_descriptor* %0
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture, i64, i32, i1) #1

; Function Attrs: nounwind uwtable
define i64 @array_allocate_float(%struct.array_table* %table, i64 %size, float* nocapture %populate) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @array_counter, align 8, !tbaa !0
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @array_counter, align 8, !tbaa !0
  %call1 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %0, i64 %size, i64 1)
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %1 = load %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %next.i = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 5
  store %struct.array_descriptor* %1, %struct.array_descriptor** %next.i, align 8, !tbaa !3
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 3
  %2 = load i8** %array_ptr, align 8, !tbaa !3
  %3 = bitcast float* %populate to i8*
  %mul = shl i64 %size, 2
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* %3, i64 %mul, i32 1, i1 false)
  br label %return

return:                                           ; preds = %entry, %if.end
  %retval.0 = phi i64 [ %0, %if.end ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @array_allocate_string(%struct.array_table* %table, i64 %size, i64* nocapture %populate) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @array_counter, align 8, !tbaa !0
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @array_counter, align 8, !tbaa !0
  %call1 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %0, i64 %size, i64 4)
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %1 = load %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %next.i = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 5
  store %struct.array_descriptor* %1, %struct.array_descriptor** %next.i, align 8, !tbaa !3
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 3
  %2 = load i8** %array_ptr, align 8, !tbaa !3
  %3 = bitcast i64* %populate to i8*
  %mul = shl i64 %size, 3
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* %3, i64 %mul, i32 1, i1 false)
  br label %return

return:                                           ; preds = %entry, %if.end
  %retval.0 = phi i64 [ %0, %if.end ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @array_allocate_char(%struct.array_table* %table, i64 %size, i8* nocapture %populate) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @array_counter, align 8, !tbaa !0
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @array_counter, align 8, !tbaa !0
  %call1 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %0, i64 %size, i64 3)
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %1 = load %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %next.i = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 5
  store %struct.array_descriptor* %1, %struct.array_descriptor** %next.i, align 8, !tbaa !3
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 3
  %2 = load i8** %array_ptr, align 8, !tbaa !3
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* %populate, i64 %size, i32 1, i1 false)
  br label %return

return:                                           ; preds = %entry, %if.end
  %retval.0 = phi i64 [ %0, %if.end ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @array_allocate_bool(%struct.array_table* %table, i64 %size, i8* nocapture %populate) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %0 = load i64* @array_counter, align 8, !tbaa !0
  %inc.i = add i64 %0, 1
  store i64 %inc.i, i64* @array_counter, align 8, !tbaa !0
  %call1 = tail call fastcc %struct.array_descriptor* @new_array_descriptor(i64 %0, i64 %size, i64 2)
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %1 = load %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %next.i = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 5
  store %struct.array_descriptor* %1, %struct.array_descriptor** %next.i, align 8, !tbaa !3
  store %struct.array_descriptor* %call1, %struct.array_descriptor** %head.i, align 8, !tbaa !3
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %call1, i64 0, i32 3
  %2 = load i8** %array_ptr, align 8, !tbaa !3
  tail call void @llvm.memcpy.p0i8.p0i8.i64(i8* %2, i8* %populate, i64 %size, i32 1, i1 false)
  br label %return

return:                                           ; preds = %entry, %if.end
  %retval.0 = phi i64 [ %0, %if.end ], [ 0, %entry ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define void @array_add_reference(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %ref_count = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 4
  %1 = load i64* %ref_count, align 8, !tbaa !0
  %inc = add i64 %1, 1
  store i64 %inc, i64* %ref_count, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_rm_reference(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %if.end6, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %if.end6, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %if.end6, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %ref_count = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 4
  %1 = load i64* %ref_count, align 8, !tbaa !0
  %dec = add i64 %1, -1
  store i64 %dec, i64* %ref_count, align 8, !tbaa !0
  %cmp.not = icmp eq i64 %dec, 0
  br i1 %cmp.not, label %if.end.i, label %if.end6

if.end.i:                                         ; preds = %if.end3
  %current.022.i = load %struct.array_descriptor** %head.i, align 8
  %tobool123.i = icmp eq %struct.array_descriptor* %current.022.i, null
  br i1 %tobool123.i, label %if.end6, label %while.body.i18

while.cond.i15:                                   ; preds = %while.body.i18
  %next10.i = getelementptr inbounds %struct.array_descriptor* %current.025.i, i64 0, i32 5
  %current.0.i14 = load %struct.array_descriptor** %next10.i, align 8
  %tobool1.i = icmp eq %struct.array_descriptor* %current.0.i14, null
  br i1 %tobool1.i, label %if.end6, label %while.body.i18

while.body.i18:                                   ; preds = %if.end.i, %while.cond.i15
  %current.025.i = phi %struct.array_descriptor* [ %current.0.i14, %while.cond.i15 ], [ %current.022.i, %if.end.i ]
  %previous.024.i = phi %struct.array_descriptor* [ %current.025.i, %while.cond.i15 ], [ null, %if.end.i ]
  %array_id.i16 = getelementptr inbounds %struct.array_descriptor* %current.025.i, i64 0, i32 0
  %2 = load i64* %array_id.i16, align 8, !tbaa !0
  %cmp.i17 = icmp eq i64 %2, %arrid
  br i1 %cmp.i17, label %if.then2.i, label %while.cond.i15

if.then2.i:                                       ; preds = %while.body.i18
  %cmp3.i = icmp eq %struct.array_descriptor* %previous.024.i, null
  %next.i19 = getelementptr inbounds %struct.array_descriptor* %current.025.i, i64 0, i32 5
  %3 = load %struct.array_descriptor** %next.i19, align 8, !tbaa !3
  br i1 %cmp3.i, label %if.else.i, label %if.then4.i

if.then4.i:                                       ; preds = %if.then2.i
  %next5.i = getelementptr inbounds %struct.array_descriptor* %previous.024.i, i64 0, i32 5
  store %struct.array_descriptor* %3, %struct.array_descriptor** %next5.i, align 8, !tbaa !3
  br label %array_descriptor_deallocate.exit.i

if.else.i:                                        ; preds = %if.then2.i
  store %struct.array_descriptor* %3, %struct.array_descriptor** %head.i, align 8, !tbaa !3
  br label %array_descriptor_deallocate.exit.i

array_descriptor_deallocate.exit.i:               ; preds = %if.else.i, %if.then4.i
  %array_ptr.i.i = getelementptr inbounds %struct.array_descriptor* %current.025.i, i64 0, i32 3
  %4 = load i8** %array_ptr.i.i, align 8, !tbaa !3
  tail call void @free(i8* %4) #1
  %5 = bitcast %struct.array_descriptor* %current.025.i to i8*
  tail call void @free(i8* %5) #1
  br label %if.end6

if.end6:                                          ; preds = %while.cond.i, %while.cond.i15, %if.end3, %if.end, %array_descriptor_deallocate.exit.i, %if.end.i, %entry
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_deallocate(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %while.end, label %if.end

if.end:                                           ; preds = %entry
  %head = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.022 = load %struct.array_descriptor** %head, align 8
  %tobool123 = icmp eq %struct.array_descriptor* %current.022, null
  br i1 %tobool123, label %while.end, label %while.body

while.cond:                                       ; preds = %while.body
  %next10 = getelementptr inbounds %struct.array_descriptor* %current.025, i64 0, i32 5
  %current.0 = load %struct.array_descriptor** %next10, align 8
  %tobool1 = icmp eq %struct.array_descriptor* %current.0, null
  br i1 %tobool1, label %while.end, label %while.body

while.body:                                       ; preds = %if.end, %while.cond
  %current.025 = phi %struct.array_descriptor* [ %current.0, %while.cond ], [ %current.022, %if.end ]
  %previous.024 = phi %struct.array_descriptor* [ %current.025, %while.cond ], [ null, %if.end ]
  %array_id = getelementptr inbounds %struct.array_descriptor* %current.025, i64 0, i32 0
  %0 = load i64* %array_id, align 8, !tbaa !0
  %cmp = icmp eq i64 %0, %arrid
  br i1 %cmp, label %if.then2, label %while.cond

if.then2:                                         ; preds = %while.body
  %cmp3 = icmp eq %struct.array_descriptor* %previous.024, null
  %next = getelementptr inbounds %struct.array_descriptor* %current.025, i64 0, i32 5
  %1 = load %struct.array_descriptor** %next, align 8, !tbaa !3
  br i1 %cmp3, label %if.else, label %if.then4

if.then4:                                         ; preds = %if.then2
  %next5 = getelementptr inbounds %struct.array_descriptor* %previous.024, i64 0, i32 5
  store %struct.array_descriptor* %1, %struct.array_descriptor** %next5, align 8, !tbaa !3
  br label %array_descriptor_deallocate.exit

if.else:                                          ; preds = %if.then2
  store %struct.array_descriptor* %1, %struct.array_descriptor** %head, align 8, !tbaa !3
  br label %array_descriptor_deallocate.exit

array_descriptor_deallocate.exit:                 ; preds = %if.else, %if.then4
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.025, i64 0, i32 3
  %2 = load i8** %array_ptr.i, align 8, !tbaa !3
  tail call void @free(i8* %2) #1
  %3 = bitcast %struct.array_descriptor* %current.025 to i8*
  tail call void @free(i8* %3) #1
  br label %while.end

while.end:                                        ; preds = %if.end, %while.cond, %entry, %array_descriptor_deallocate.exit
  ret void
}

; Function Attrs: nounwind readonly uwtable
define i64 @array_size(%struct.array_table* %table, i64 %arrid) #2 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %1 = load i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i64 [ %1, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind readonly uwtable
define i64 @array_ref_count(%struct.array_table* %table, i64 %arrid) #2 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %ref_count = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 4
  %1 = load i64* %ref_count, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  %retval.0 = phi i64 [ %1, %if.end3 ], [ 0, %entry ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define void @array_insert_int(%struct.array_table* %table, i64 %arrid, i32 %value, i64 %pos) #0 {
entry:
  %value.addr = alloca i32, align 4
  store i32 %value, i32* %value.addr, align 4
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 0
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %2 = load i8** %array_ptr.i, align 8, !tbaa !3
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %3 = load i64* %array_size.i, align 8, !tbaa !0
  %add.i = shl i64 %3, 2
  %mul.i = add i64 %add.i, 4
  %call1.i = call i8* @realloc(i8* %2, i64 %mul.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i7 = icmp eq i8* %call1.i, null
  br i1 %tobool.i7, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %pos
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = sub i64 %8, %pos
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  %value.addr.0.cast = bitcast i32* %value.addr to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr.0.cast, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_bool(%struct.array_table* %table, i64 %arrid, i1 zeroext %value, i64 %pos) #0 {
entry:
  %value.addr = alloca i8, align 1
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 2
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %2 = load i8** %array_ptr.i, align 8, !tbaa !3
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %3 = load i64* %array_size.i, align 8, !tbaa !0
  %add.i = add i64 %3, 1
  %call1.i = call i8* @realloc(i8* %2, i64 %add.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i7 = icmp eq i8* %call1.i, null
  br i1 %tobool.i7, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %pos
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = sub i64 %8, %pos
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_float(%struct.array_table* %table, i64 %arrid, float %value, i64 %pos) #0 {
entry:
  %value.addr = alloca float, align 4
  store float %value, float* %value.addr, align 4
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 1
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %2 = load i8** %array_ptr.i, align 8, !tbaa !3
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %3 = load i64* %array_size.i, align 8, !tbaa !0
  %add.i = shl i64 %3, 2
  %mul.i = add i64 %add.i, 4
  %call1.i = call i8* @realloc(i8* %2, i64 %mul.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i7 = icmp eq i8* %call1.i, null
  br i1 %tobool.i7, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %pos
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = sub i64 %8, %pos
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  %value.addr.0.cast = bitcast float* %value.addr to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr.0.cast, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_char(%struct.array_table* %table, i64 %arrid, i8 signext %value, i64 %pos) #0 {
entry:
  %value.addr = alloca i8, align 1
  store i8 %value, i8* %value.addr, align 1
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 3
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %2 = load i8** %array_ptr.i, align 8, !tbaa !3
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %3 = load i64* %array_size.i, align 8, !tbaa !0
  %add.i = add i64 %3, 1
  %call1.i = call i8* @realloc(i8* %2, i64 %add.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i7 = icmp eq i8* %call1.i, null
  br i1 %tobool.i7, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %pos
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = sub i64 %8, %pos
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_insert_string(%struct.array_table* %table, i64 %arrid, i64 %value, i64 %pos) #0 {
entry:
  %value.addr = alloca i64, align 8
  store i64 %value, i64* %value.addr, align 8
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 4
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %2 = load i8** %array_ptr.i, align 8, !tbaa !3
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %3 = load i64* %array_size.i, align 8, !tbaa !0
  %add.i = shl i64 %3, 3
  %mul.i = add i64 %add.i, 8
  %call1.i = call i8* @realloc(i8* %2, i64 %mul.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i7 = icmp eq i8* %call1.i, null
  br i1 %tobool.i7, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %pos
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = sub i64 %8, %pos
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  %value.addr.0.cast = bitcast i64* %value.addr to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr.0.cast, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind readonly uwtable
define i32 @array_get_int(%struct.array_table* %table, i64 %arrid, i64 %pos) #2 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 0
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx8 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx8.val = load i8** %call.idx8, align 8, !tbaa !3
  %mul.i = shl i64 %pos, 2
  %add.ptr.i = getelementptr i8* %call.idx8.val, i64 %mul.i
  %2 = bitcast i8* %add.ptr.i to i32*
  %3 = load i32* %2, align 4, !tbaa !4
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %if.end3
  %retval.0 = phi i32 [ %3, %if.end3 ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind readonly uwtable
define float @array_get_float(%struct.array_table* %table, i64 %arrid, i64 %pos) #2 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 1
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx8 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx8.val = load i8** %call.idx8, align 8, !tbaa !3
  %mul.i = shl i64 %pos, 2
  %add.ptr.i = getelementptr i8* %call.idx8.val, i64 %mul.i
  %2 = bitcast i8* %add.ptr.i to float*
  %3 = load float* %2, align 4, !tbaa !5
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %if.end3
  %retval.0 = phi float [ %3, %if.end3 ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %lor.lhs.false ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @array_get_bool(%struct.array_table* %table, i64 %arrid, i64 %pos) #2 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 2
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx9 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx9.val = load i8** %call.idx9, align 8, !tbaa !3
  %add.ptr.i = getelementptr i8* %call.idx9.val, i64 %pos
  %2 = load i8* %add.ptr.i, align 1, !tbaa !6, !range !7
  %tobool5 = icmp ne i8 %2, 0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %if.end3
  %retval.0 = phi i1 [ %tobool5, %if.end3 ], [ false, %entry ], [ false, %lor.lhs.false ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind readonly uwtable
define signext i8 @array_get_char(%struct.array_table* %table, i64 %arrid, i64 %pos) #2 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 3
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx8 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx8.val = load i8** %call.idx8, align 8, !tbaa !3
  %add.ptr.i = getelementptr i8* %call.idx8.val, i64 %pos
  %2 = load i8* %add.ptr.i, align 1, !tbaa !1
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %if.end3
  %retval.0 = phi i8 [ %2, %if.end3 ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind readonly uwtable
define i64 @array_get_string(%struct.array_table* %table, i64 %arrid, i64 %pos) #2 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 4
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx8 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx8.val = load i8** %call.idx8, align 8, !tbaa !3
  %mul.i = shl i64 %pos, 3
  %add.ptr.i = getelementptr i8* %call.idx8.val, i64 %mul.i
  %2 = bitcast i8* %add.ptr.i to i64*
  %3 = load i64* %2, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %if.end3
  %retval.0 = phi i64 [ %3, %if.end3 ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define void @array_clear(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %array_ptr = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i8** %array_ptr, align 8, !tbaa !3
  tail call void @free(i8* %1) #1
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  store i64 0, i64* %array_size, align 8, !tbaa !0
  store i8* null, i8** %array_ptr, align 8, !tbaa !3
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %if.end3
  ret void
}

; Function Attrs: nounwind
declare void @free(i8* nocapture) #3

; Function Attrs: nounwind uwtable
define void @array_remove(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %if.end3, label %while.cond.i

if.end3:                                          ; preds = %while.body.i
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %1 = load i8** %array_ptr.i, align 8, !tbaa !3
  %type.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %2 = load i64* %type.i, align 8, !tbaa !0
  %arrayidx.i.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %2
  %3 = load i64* %arrayidx.i.i, align 8, !tbaa !0
  %mul.i = mul i64 %3, %pos
  %add.ptr.i = getelementptr i8* %1, i64 %mul.i
  %add.ptr.sum.i = add i64 %mul.i, %3
  %add.ptr3.i = getelementptr i8* %1, i64 %add.ptr.sum.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %4 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = xor i64 %pos, -1
  %sub6.i = add i64 %4, %sub.i
  %mul7.i = mul i64 %sub6.i, %3
  tail call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %add.ptr3.i, i64 %mul7.i, i32 1, i1 false) #1
  %5 = load i8** %array_ptr.i, align 8, !tbaa !3
  %6 = load i64* %type.i, align 8, !tbaa !0
  %arrayidx.i31.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i31.i, align 8, !tbaa !0
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub12.i = add i64 %8, -1
  %mul13.i = mul i64 %sub12.i, %7
  %call14.i = tail call i8* @realloc(i8* %5, i64 %mul13.i) #1
  store i8* %call14.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i6 = icmp eq i8* %call14.i, null
  br i1 %tobool.i6, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %9 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %10 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %9) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %11 = load i64* %array_size.i, align 8, !tbaa !0
  %dec.i = add i64 %11, -1
  store i64 %dec.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %entry, %array_remove_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @array_remove_int(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 0
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx10 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx10.val = load i8** %call.idx10, align 8, !tbaa !3
  %mul.i13 = shl i64 %pos, 2
  %add.ptr.i14 = getelementptr i8* %call.idx10.val, i64 %mul.i13
  %2 = bitcast i8* %add.ptr.i14 to i32*
  %3 = load i32* %2, align 4, !tbaa !4
  %add.ptr.sum.i = add i64 %mul.i13, 4
  %add.ptr3.i = getelementptr i8* %call.idx10.val, i64 %add.ptr.sum.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %4 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = xor i64 %pos, 4611686018427387903
  %sub6.i = add i64 %4, %sub.i
  %mul7.i = shl i64 %sub6.i, 2
  tail call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr.i14, i8* %add.ptr3.i, i64 %mul7.i, i32 1, i1 false) #1
  %5 = load i8** %call.idx10, align 8, !tbaa !3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i31.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i31.i, align 8, !tbaa !0
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub12.i = add i64 %8, -1
  %mul13.i = mul i64 %sub12.i, %7
  %call14.i = tail call i8* @realloc(i8* %5, i64 %mul13.i) #1
  store i8* %call14.i, i8** %call.idx10, align 8, !tbaa !3
  %tobool.i11 = icmp eq i8* %call14.i, null
  br i1 %tobool.i11, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %9 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %10 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %9) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %11 = load i64* %array_size.i, align 8, !tbaa !0
  %dec.i = add i64 %11, -1
  store i64 %dec.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi i32 [ %3, %array_remove_value.exit ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind uwtable
define float @array_remove_float(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 1
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx10 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx10.val = load i8** %call.idx10, align 8, !tbaa !3
  %mul.i13 = shl i64 %pos, 2
  %add.ptr.i14 = getelementptr i8* %call.idx10.val, i64 %mul.i13
  %2 = bitcast i8* %add.ptr.i14 to float*
  %3 = load float* %2, align 4, !tbaa !5
  %add.ptr.sum.i = add i64 %mul.i13, 4
  %add.ptr3.i = getelementptr i8* %call.idx10.val, i64 %add.ptr.sum.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %4 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = xor i64 %pos, 4611686018427387903
  %sub6.i = add i64 %4, %sub.i
  %mul7.i = shl i64 %sub6.i, 2
  tail call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr.i14, i8* %add.ptr3.i, i64 %mul7.i, i32 1, i1 false) #1
  %5 = load i8** %call.idx10, align 8, !tbaa !3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i31.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i31.i, align 8, !tbaa !0
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub12.i = add i64 %8, -1
  %mul13.i = mul i64 %sub12.i, %7
  %call14.i = tail call i8* @realloc(i8* %5, i64 %mul13.i) #1
  store i8* %call14.i, i8** %call.idx10, align 8, !tbaa !3
  %tobool.i11 = icmp eq i8* %call14.i, null
  br i1 %tobool.i11, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %9 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %10 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %9) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %11 = load i64* %array_size.i, align 8, !tbaa !0
  %dec.i = add i64 %11, -1
  store i64 %dec.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi float [ %3, %array_remove_value.exit ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %lor.lhs.false ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind uwtable
define zeroext i1 @array_remove_bool(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 2
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx12 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx12.val = load i8** %call.idx12, align 8, !tbaa !3
  %add.ptr.i16 = getelementptr i8* %call.idx12.val, i64 %pos
  %2 = load i8* %add.ptr.i16, align 1, !tbaa !6, !range !7
  %add.ptr.sum.i = add i64 %pos, 1
  %add.ptr3.i = getelementptr i8* %call.idx12.val, i64 %add.ptr.sum.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %3 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = xor i64 %pos, -1
  %sub6.i = add i64 %3, %sub.i
  tail call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr.i16, i8* %add.ptr3.i, i64 %sub6.i, i32 1, i1 false) #1
  %4 = load i8** %call.idx12, align 8, !tbaa !3
  %5 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i31.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %5
  %6 = load i64* %arrayidx.i31.i, align 8, !tbaa !0
  %7 = load i64* %array_size.i, align 8, !tbaa !0
  %sub12.i = add i64 %7, -1
  %mul13.i = mul i64 %sub12.i, %6
  %call14.i = tail call i8* @realloc(i8* %4, i64 %mul13.i) #1
  store i8* %call14.i, i8** %call.idx12, align 8, !tbaa !3
  %tobool.i13 = icmp eq i8* %call14.i, null
  br i1 %tobool.i13, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %8 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %8) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %tobool5 = icmp ne i8 %2, 0
  %10 = load i64* %array_size.i, align 8, !tbaa !0
  %dec.i = add i64 %10, -1
  store i64 %dec.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi i1 [ %tobool5, %array_remove_value.exit ], [ false, %entry ], [ false, %lor.lhs.false ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind uwtable
define signext i8 @array_remove_char(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 3
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx10 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx10.val = load i8** %call.idx10, align 8, !tbaa !3
  %add.ptr.i14 = getelementptr i8* %call.idx10.val, i64 %pos
  %2 = load i8* %add.ptr.i14, align 1, !tbaa !1
  %add.ptr.sum.i = add i64 %pos, 1
  %add.ptr3.i = getelementptr i8* %call.idx10.val, i64 %add.ptr.sum.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %3 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = xor i64 %pos, -1
  %sub6.i = add i64 %3, %sub.i
  tail call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr.i14, i8* %add.ptr3.i, i64 %sub6.i, i32 1, i1 false) #1
  %4 = load i8** %call.idx10, align 8, !tbaa !3
  %5 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i31.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %5
  %6 = load i64* %arrayidx.i31.i, align 8, !tbaa !0
  %7 = load i64* %array_size.i, align 8, !tbaa !0
  %sub12.i = add i64 %7, -1
  %mul13.i = mul i64 %sub12.i, %6
  %call14.i = tail call i8* @realloc(i8* %4, i64 %mul13.i) #1
  store i8* %call14.i, i8** %call.idx10, align 8, !tbaa !3
  %tobool.i11 = icmp eq i8* %call14.i, null
  br i1 %tobool.i11, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %8 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %9 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %8) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %10 = load i64* %array_size.i, align 8, !tbaa !0
  %dec.i = add i64 %10, -1
  store i64 %dec.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi i8 [ %2, %array_remove_value.exit ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @array_remove_string(%struct.array_table* %table, i64 %arrid, i64 %pos) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 4
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %call.idx10 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx10.val = load i8** %call.idx10, align 8, !tbaa !3
  %mul.i13 = shl i64 %pos, 3
  %add.ptr.i14 = getelementptr i8* %call.idx10.val, i64 %mul.i13
  %2 = bitcast i8* %add.ptr.i14 to i64*
  %3 = load i64* %2, align 8, !tbaa !0
  %add.ptr.sum.i = add i64 %mul.i13, 8
  %add.ptr3.i = getelementptr i8* %call.idx10.val, i64 %add.ptr.sum.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %4 = load i64* %array_size.i, align 8, !tbaa !0
  %sub.i = xor i64 %pos, 2305843009213693951
  %sub6.i = add i64 %4, %sub.i
  %mul7.i = shl i64 %sub6.i, 3
  tail call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr.i14, i8* %add.ptr3.i, i64 %mul7.i, i32 1, i1 false) #1
  %5 = load i8** %call.idx10, align 8, !tbaa !3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i31.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i31.i, align 8, !tbaa !0
  %8 = load i64* %array_size.i, align 8, !tbaa !0
  %sub12.i = add i64 %8, -1
  %mul13.i = mul i64 %sub12.i, %7
  %call14.i = tail call i8* @realloc(i8* %5, i64 %mul13.i) #1
  store i8* %call14.i, i8** %call.idx10, align 8, !tbaa !3
  %tobool.i11 = icmp eq i8* %call14.i, null
  br i1 %tobool.i11, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %9 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %10 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %9) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %11 = load i64* %array_size.i, align 8, !tbaa !0
  %dec.i = add i64 %11, -1
  store i64 %dec.i, i64* %array_size.i, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi i64 [ %3, %array_remove_value.exit ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define i32 @array_pop_int(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 0
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %call.idx11 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx11.val = load i8** %call.idx11, align 8, !tbaa !3
  %sub = shl i64 %2, 2
  %mul.i14 = add i64 %sub, -4
  %add.ptr.i15 = getelementptr i8* %call.idx11.val, i64 %mul.i14
  %3 = bitcast i8* %add.ptr.i15 to i32*
  %4 = load i32* %3, align 4, !tbaa !4
  %call14.i = tail call i8* @realloc(i8* %call.idx11.val, i64 %mul.i14) #1
  store i8* %call14.i, i8** %call.idx11, align 8, !tbaa !3
  %tobool.i12 = icmp eq i8* %call14.i, null
  br i1 %tobool.i12, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %5 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %6 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %5) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %7 = load i64* %array_size, align 8, !tbaa !0
  %dec.i = add i64 %7, -1
  store i64 %dec.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi i32 [ %4, %array_remove_value.exit ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i32 %retval.0
}

; Function Attrs: nounwind uwtable
define float @array_pop_float(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 1
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %call.idx11 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx11.val = load i8** %call.idx11, align 8, !tbaa !3
  %sub = shl i64 %2, 2
  %mul.i14 = add i64 %sub, -4
  %add.ptr.i15 = getelementptr i8* %call.idx11.val, i64 %mul.i14
  %3 = bitcast i8* %add.ptr.i15 to float*
  %4 = load float* %3, align 4, !tbaa !5
  %call14.i = tail call i8* @realloc(i8* %call.idx11.val, i64 %mul.i14) #1
  store i8* %call14.i, i8** %call.idx11, align 8, !tbaa !3
  %tobool.i12 = icmp eq i8* %call14.i, null
  br i1 %tobool.i12, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %5 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %6 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %5) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %7 = load i64* %array_size, align 8, !tbaa !0
  %dec.i = add i64 %7, -1
  store i64 %dec.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi float [ %4, %array_remove_value.exit ], [ 0.000000e+00, %entry ], [ 0.000000e+00, %lor.lhs.false ], [ 0.000000e+00, %if.end ], [ 0.000000e+00, %while.cond.i ]
  ret float %retval.0
}

; Function Attrs: nounwind uwtable
define zeroext i1 @array_pop_bool(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 2
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %sub = add i64 %2, -1
  %call.idx13 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx13.val = load i8** %call.idx13, align 8, !tbaa !3
  %add.ptr.i17 = getelementptr i8* %call.idx13.val, i64 %sub
  %3 = load i8* %add.ptr.i17, align 1, !tbaa !6, !range !7
  %call14.i = tail call i8* @realloc(i8* %call.idx13.val, i64 %sub) #1
  store i8* %call14.i, i8** %call.idx13, align 8, !tbaa !3
  %tobool.i14 = icmp eq i8* %call14.i, null
  br i1 %tobool.i14, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %tobool5 = icmp ne i8 %3, 0
  %6 = load i64* %array_size, align 8, !tbaa !0
  %dec.i = add i64 %6, -1
  store i64 %dec.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi i1 [ %tobool5, %array_remove_value.exit ], [ false, %entry ], [ false, %lor.lhs.false ], [ false, %if.end ], [ false, %while.cond.i ]
  ret i1 %retval.0
}

; Function Attrs: nounwind uwtable
define signext i8 @array_pop_char(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 3
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %sub = add i64 %2, -1
  %call.idx11 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx11.val = load i8** %call.idx11, align 8, !tbaa !3
  %add.ptr.i15 = getelementptr i8* %call.idx11.val, i64 %sub
  %3 = load i8* %add.ptr.i15, align 1, !tbaa !1
  %call14.i = tail call i8* @realloc(i8* %call.idx11.val, i64 %sub) #1
  store i8* %call14.i, i8** %call.idx11, align 8, !tbaa !3
  %tobool.i12 = icmp eq i8* %call14.i, null
  br i1 %tobool.i12, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %6 = load i64* %array_size, align 8, !tbaa !0
  %dec.i = add i64 %6, -1
  store i64 %dec.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi i8 [ %3, %array_remove_value.exit ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i8 %retval.0
}

; Function Attrs: nounwind uwtable
define i64 @array_pop_string(%struct.array_table* %table, i64 %arrid) #0 {
entry:
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 4
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %call.idx11 = getelementptr %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %call.idx11.val = load i8** %call.idx11, align 8, !tbaa !3
  %sub = shl i64 %2, 3
  %mul.i14 = add i64 %sub, -8
  %add.ptr.i15 = getelementptr i8* %call.idx11.val, i64 %mul.i14
  %3 = bitcast i8* %add.ptr.i15 to i64*
  %4 = load i64* %3, align 8, !tbaa !0
  %call14.i = tail call i8* @realloc(i8* %call.idx11.val, i64 %mul.i14) #1
  store i8* %call14.i, i8** %call.idx11, align 8, !tbaa !3
  %tobool.i12 = icmp eq i8* %call14.i, null
  br i1 %tobool.i12, label %if.then.i, label %array_remove_value.exit

if.then.i:                                        ; preds = %if.end3
  %5 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %6 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str1, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %5) #1
  tail call void @exit(i32 1) #5
  unreachable

array_remove_value.exit:                          ; preds = %if.end3
  %7 = load i64* %array_size, align 8, !tbaa !0
  %dec.i = add i64 %7, -1
  store i64 %dec.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_remove_value.exit
  %retval.0 = phi i64 [ %4, %array_remove_value.exit ], [ 0, %entry ], [ 0, %lor.lhs.false ], [ 0, %if.end ], [ 0, %while.cond.i ]
  ret i64 %retval.0
}

; Function Attrs: nounwind uwtable
define void @array_push_int(%struct.array_table* %table, i64 %arrid, i32 %value) #0 {
entry:
  %value.addr = alloca i32, align 4
  store i32 %value, i32* %value.addr, align 4
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 0
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %3 = load i8** %array_ptr.i, align 8, !tbaa !3
  %add.i = shl i64 %2, 2
  %mul.i = add i64 %add.i, 4
  %call1.i = call i8* @realloc(i8* %3, i64 %mul.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i8 = icmp eq i8* %call1.i, null
  br i1 %tobool.i8, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %2
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size, align 8, !tbaa !0
  %sub.i = sub i64 %8, %2
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  %value.addr.0.cast = bitcast i32* %value.addr to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr.0.cast, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_push_float(%struct.array_table* %table, i64 %arrid, float %value) #0 {
entry:
  %value.addr = alloca float, align 4
  store float %value, float* %value.addr, align 4
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 1
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %3 = load i8** %array_ptr.i, align 8, !tbaa !3
  %add.i = shl i64 %2, 2
  %mul.i = add i64 %add.i, 4
  %call1.i = call i8* @realloc(i8* %3, i64 %mul.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i8 = icmp eq i8* %call1.i, null
  br i1 %tobool.i8, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %2
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size, align 8, !tbaa !0
  %sub.i = sub i64 %8, %2
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  %value.addr.0.cast = bitcast float* %value.addr to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr.0.cast, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_push_bool(%struct.array_table* %table, i64 %arrid, i1 zeroext %value) #0 {
entry:
  %value.addr = alloca i8, align 1
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 2
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %3 = load i8** %array_ptr.i, align 8, !tbaa !3
  %add.i = add i64 %2, 1
  %call1.i = call i8* @realloc(i8* %3, i64 %add.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i8 = icmp eq i8* %call1.i, null
  br i1 %tobool.i8, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %2
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size, align 8, !tbaa !0
  %sub.i = sub i64 %8, %2
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_push_char(%struct.array_table* %table, i64 %arrid, i8 signext %value) #0 {
entry:
  %value.addr = alloca i8, align 1
  store i8 %value, i8* %value.addr, align 1
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 3
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %3 = load i8** %array_ptr.i, align 8, !tbaa !3
  %add.i = add i64 %2, 1
  %call1.i = call i8* @realloc(i8* %3, i64 %add.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i8 = icmp eq i8* %call1.i, null
  br i1 %tobool.i8, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %2
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size, align 8, !tbaa !0
  %sub.i = sub i64 %8, %2
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_push_string(%struct.array_table* %table, i64 %arrid, i64 %value) #0 {
entry:
  %value.addr = alloca i64, align 8
  store i64 %value, i64* %value.addr, align 8
  %tobool = icmp eq %struct.array_table* %table, null
  br i1 %tobool, label %return, label %if.end

if.end:                                           ; preds = %entry
  %head.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i = load %struct.array_descriptor** %head.i, align 8
  %tobool4.i = icmp eq %struct.array_descriptor* %current.03.i, null
  br i1 %tobool4.i, label %return, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i, align 8
  %tobool.i = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i, label %return, label %while.body.i

while.body.i:                                     ; preds = %if.end, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %current.03.i, %if.end ]
  %array_id.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %0 = load i64* %array_id.i, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %0, %arrid
  br i1 %cmp.i, label %lor.lhs.false, label %while.cond.i

lor.lhs.false:                                    ; preds = %while.body.i
  %type = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 2
  %1 = load i64* %type, align 8, !tbaa !0
  %cmp = icmp eq i64 %1, 4
  br i1 %cmp, label %if.end3, label %return

if.end3:                                          ; preds = %lor.lhs.false
  %array_size = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 1
  %2 = load i64* %array_size, align 8, !tbaa !0
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 3
  %3 = load i8** %array_ptr.i, align 8, !tbaa !3
  %add.i = shl i64 %2, 3
  %mul.i = add i64 %add.i, 8
  %call1.i = call i8* @realloc(i8* %3, i64 %mul.i) #1
  store i8* %call1.i, i8** %array_ptr.i, align 8, !tbaa !3
  %tobool.i8 = icmp eq i8* %call1.i, null
  br i1 %tobool.i8, label %if.then.i, label %array_insert_value.exit

if.then.i:                                        ; preds = %if.end3
  %4 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %5 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %4) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %if.end3
  %6 = load i64* %type, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %6
  %7 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %7, %2
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %7
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %8 = load i64* %array_size, align 8, !tbaa !0
  %sub.i = sub i64 %8, %2
  %mul15.i = mul i64 %sub.i, %7
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  %value.addr.0.cast = bitcast i64* %value.addr to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %value.addr.0.cast, i64 %7, i32 1, i1 false) #1
  %inc.i = add i64 %8, 1
  store i64 %inc.i, i64* %array_size, align 8, !tbaa !0
  br label %return

return:                                           ; preds = %while.cond.i, %if.end, %lor.lhs.false, %entry, %array_insert_value.exit
  ret void
}

; Function Attrs: nounwind uwtable
define noalias %struct.array_table* @create_array_table() #0 {
entry:
  %call = tail call noalias i8* @malloc(i64 8) #1
  %0 = bitcast i8* %call to %struct.array_table*
  %tobool = icmp eq i8* %call, null
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %2 = tail call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %1)
  br label %if.end

if.end:                                           ; preds = %entry, %if.then
  %head = bitcast i8* %call to %struct.array_descriptor**
  store %struct.array_descriptor* null, %struct.array_descriptor** %head, align 8, !tbaa !3
  ret %struct.array_table* %0
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #3

; Function Attrs: nounwind uwtable
define void @delete_array_table(%struct.array_table* nocapture %table) #0 {
entry:
  %0 = bitcast %struct.array_table* %table to i8*
  tail call void @free(i8* %0) #1
  ret void
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @array_empty(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i, align 8, !tbaa !0
  %phitmp = icmp eq i64 %1, 0
  br label %array_size.exit

array_size.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i1 [ %phitmp, %if.end3.i ], [ true, %entry ], [ true, %if.end.i ], [ true, %while.cond.i.i ]
  ret i1 %retval.0.i
}

; Function Attrs: nounwind uwtable
define i64 @array_make_sequence(%struct.array_table* %table, i64 %a, i64 %b) #0 {
entry:
  %i = alloca i64, align 8
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %find_array_descriptor.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %0 = load i64* @array_counter, align 8, !tbaa !0
  %inc.i.i = add i64 %0, 1
  store i64 %inc.i.i, i64* @array_counter, align 8, !tbaa !0
  %call.i = call noalias i8* @malloc(i64 48) #1
  %tobool.i5 = icmp eq i8* %call.i, null
  br i1 %tobool.i5, label %if.then.i, label %array_allocate_int.exit

if.then.i:                                        ; preds = %if.end.i
  %1 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %2 = call i64 @fwrite(i8* getelementptr inbounds ([53 x i8]* @.str3, i64 0, i64 0), i64 52, i64 1, %struct._IO_FILE* %1) #1
  call void @exit(i32 1) #5
  unreachable

array_allocate_int.exit:                          ; preds = %if.end.i
  %3 = bitcast i8* %call.i to %struct.array_descriptor*
  %array_id.i = bitcast i8* %call.i to i64*
  store i64 %0, i64* %array_id.i, align 8, !tbaa !0
  %array_size.i = getelementptr inbounds i8* %call.i, i64 8
  %next.i = getelementptr inbounds i8* %call.i, i64 40
  %4 = bitcast i8* %next.i to %struct.array_descriptor**
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  call void @llvm.memset.p0i8.i64(i8* %array_size.i, i8 0, i64 32, i32 8, i1 false)
  %5 = load %struct.array_descriptor** %head.i.i, align 8, !tbaa !3
  store %struct.array_descriptor* %5, %struct.array_descriptor** %4, align 8, !tbaa !3
  store %struct.array_descriptor* %3, %struct.array_descriptor** %head.i.i, align 8, !tbaa !3
  %tobool4.i = icmp eq i8* %call.i, null
  br i1 %tobool4.i, label %find_array_descriptor.exit, label %while.body.i

while.cond.i:                                     ; preds = %while.body.i
  %next.i7 = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 5
  %current.0.i = load %struct.array_descriptor** %next.i7, align 8
  %tobool.i8 = icmp eq %struct.array_descriptor* %current.0.i, null
  br i1 %tobool.i8, label %find_array_descriptor.exit, label %while.body.i

while.body.i:                                     ; preds = %array_allocate_int.exit, %while.cond.i
  %current.05.i = phi %struct.array_descriptor* [ %current.0.i, %while.cond.i ], [ %3, %array_allocate_int.exit ]
  %array_id.i9 = getelementptr inbounds %struct.array_descriptor* %current.05.i, i64 0, i32 0
  %6 = load i64* %array_id.i9, align 8, !tbaa !0
  %cmp.i = icmp eq i64 %6, %0
  br i1 %cmp.i, label %find_array_descriptor.exit, label %while.cond.i

find_array_descriptor.exit:                       ; preds = %entry, %while.cond.i, %while.body.i, %array_allocate_int.exit
  %retval.0.i19 = phi i64 [ %0, %array_allocate_int.exit ], [ %0, %while.body.i ], [ %0, %while.cond.i ], [ 0, %entry ]
  %retval.0.i10 = phi %struct.array_descriptor* [ null, %array_allocate_int.exit ], [ %current.05.i, %while.body.i ], [ null, %while.cond.i ], [ null, %entry ]
  store i64 %a, i64* %i, align 8
  %cmp16 = icmp ugt i64 %a, %b
  br i1 %cmp16, label %for.end, label %for.body.lr.ph

for.body.lr.ph:                                   ; preds = %find_array_descriptor.exit
  %array_size = getelementptr inbounds %struct.array_descriptor* %retval.0.i10, i64 0, i32 1
  %array_ptr.i11 = getelementptr inbounds %struct.array_descriptor* %retval.0.i10, i64 0, i32 3
  %type.i = getelementptr inbounds %struct.array_descriptor* %retval.0.i10, i64 0, i32 2
  %i.0.cast = bitcast i64* %i to i8*
  br label %for.body

for.body:                                         ; preds = %for.body.lr.ph, %array_insert_value.exit
  %7 = load i64* %array_size, align 8, !tbaa !0
  %8 = load i8** %array_ptr.i11, align 8, !tbaa !3
  %add.i = add i64 %7, 1
  %9 = load i64* %type.i, align 8, !tbaa !0
  %arrayidx.i.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %9
  %10 = load i64* %arrayidx.i.i, align 8, !tbaa !0
  %mul.i = mul i64 %10, %add.i
  %call1.i = call i8* @realloc(i8* %8, i64 %mul.i) #1
  store i8* %call1.i, i8** %array_ptr.i11, align 8, !tbaa !3
  %tobool.i13 = icmp eq i8* %call1.i, null
  br i1 %tobool.i13, label %if.then.i14, label %array_insert_value.exit

if.then.i14:                                      ; preds = %for.body
  %11 = load %struct._IO_FILE** @stderr, align 8, !tbaa !3
  %12 = call i64 @fwrite(i8* getelementptr inbounds ([51 x i8]* @.str2, i64 0, i64 0), i64 50, i64 1, %struct._IO_FILE* %11) #1
  call void @exit(i32 1) #5
  unreachable

array_insert_value.exit:                          ; preds = %for.body
  %13 = load i64* %type.i, align 8, !tbaa !0
  %arrayidx.i36.i = getelementptr inbounds [5 x i64]* @bytes_per_type, i64 0, i64 %13
  %14 = load i64* %arrayidx.i36.i, align 8, !tbaa !0
  %mul8.i = mul i64 %14, %7
  %add.ptr.i = getelementptr i8* %call1.i, i64 %mul8.i
  %add.ptr.sum.i = add i64 %mul8.i, %14
  %add.ptr11.i = getelementptr i8* %call1.i, i64 %add.ptr.sum.i
  %15 = load i64* %array_size, align 8, !tbaa !0
  %sub.i = sub i64 %15, %7
  %mul15.i = mul i64 %sub.i, %14
  call void @llvm.memmove.p0i8.p0i8.i64(i8* %add.ptr11.i, i8* %add.ptr.i, i64 %mul15.i, i32 1, i1 false) #1
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %add.ptr.i, i8* %i.0.cast, i64 %14, i32 1, i1 false) #1
  %inc.i = add i64 %15, 1
  store i64 %inc.i, i64* %array_size, align 8, !tbaa !0
  %i.0.load = load i64* %i, align 8
  %inc = add i64 %i.0.load, 1
  store i64 %inc, i64* %i, align 8
  %cmp = icmp ugt i64 %inc, %b
  br i1 %cmp, label %for.end, label %for.body

for.end:                                          ; preds = %array_insert_value.exit, %find_array_descriptor.exit
  ret i64 %retval.0.i19
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @array_empty_int(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i.i, label %array_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.array_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.array_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %array_id.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i.i, align 8, !tbaa !0
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %array_size.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i.i, align 8, !tbaa !0
  %phitmp.i = icmp eq i64 %1, 0
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @array_empty_float(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i.i, label %array_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.array_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.array_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %array_id.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i.i, align 8, !tbaa !0
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %array_size.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i.i, align 8, !tbaa !0
  %phitmp.i = icmp eq i64 %1, 0
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @array_empty_double(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i.i, label %array_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.array_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.array_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %array_id.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i.i, align 8, !tbaa !0
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %array_size.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i.i, align 8, !tbaa !0
  %phitmp.i = icmp eq i64 %1, 0
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @array_empty_char(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i.i, label %array_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.array_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.array_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %array_id.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i.i, align 8, !tbaa !0
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %array_size.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i.i, align 8, !tbaa !0
  %phitmp.i = icmp eq i64 %1, 0
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define zeroext i1 @array_empty_string(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i.i, label %array_empty.exit, label %if.end.i.i

if.end.i.i:                                       ; preds = %entry
  %head.i.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i.i = load %struct.array_descriptor** %head.i.i.i, align 8
  %tobool4.i.i.i = icmp eq %struct.array_descriptor* %current.03.i.i.i, null
  br i1 %tobool4.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.cond.i.i.i:                                 ; preds = %while.body.i.i.i
  %next.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 5
  %current.0.i.i.i = load %struct.array_descriptor** %next.i.i.i, align 8
  %tobool.i.i.i = icmp eq %struct.array_descriptor* %current.0.i.i.i, null
  br i1 %tobool.i.i.i, label %array_empty.exit, label %while.body.i.i.i

while.body.i.i.i:                                 ; preds = %if.end.i.i, %while.cond.i.i.i
  %current.05.i.i.i = phi %struct.array_descriptor* [ %current.0.i.i.i, %while.cond.i.i.i ], [ %current.03.i.i.i, %if.end.i.i ]
  %array_id.i.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i.i, align 8, !tbaa !0
  %cmp.i.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i.i, label %if.end3.i.i, label %while.cond.i.i.i

if.end3.i.i:                                      ; preds = %while.body.i.i.i
  %array_size.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i.i, align 8, !tbaa !0
  %phitmp.i = icmp eq i64 %1, 0
  br label %array_empty.exit

array_empty.exit:                                 ; preds = %while.cond.i.i.i, %entry, %if.end.i.i, %if.end3.i.i
  %retval.0.i.i = phi i1 [ %phitmp.i, %if.end3.i.i ], [ true, %entry ], [ true, %if.end.i.i ], [ true, %while.cond.i.i.i ]
  ret i1 %retval.0.i.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @array_size_int(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i, align 8, !tbaa !0
  br label %array_size.exit

array_size.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @array_size_float(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i, align 8, !tbaa !0
  br label %array_size.exit

array_size.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @array_size_double(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i, align 8, !tbaa !0
  br label %array_size.exit

array_size.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @array_size_char(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i, align 8, !tbaa !0
  br label %array_size.exit

array_size.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind readonly uwtable
define i64 @array_size_string(%struct.array_table* %table, i64 %id) #2 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_size.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_size.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_size.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  %1 = load i64* %array_size.i, align 8, !tbaa !0
  br label %array_size.exit

array_size.exit:                                  ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  %retval.0.i = phi i64 [ %1, %if.end3.i ], [ 0, %entry ], [ 0, %if.end.i ], [ 0, %while.cond.i.i ]
  ret i64 %retval.0.i
}

; Function Attrs: nounwind uwtable
define void @array_clear_int(%struct.array_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i8** %array_ptr.i, align 8, !tbaa !3
  tail call void @free(i8* %1) #1
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  store i64 0, i64* %array_size.i, align 8, !tbaa !0
  store i8* null, i8** %array_ptr.i, align 8, !tbaa !3
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_clear_float(%struct.array_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i8** %array_ptr.i, align 8, !tbaa !3
  tail call void @free(i8* %1) #1
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  store i64 0, i64* %array_size.i, align 8, !tbaa !0
  store i8* null, i8** %array_ptr.i, align 8, !tbaa !3
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_clear_double(%struct.array_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i8** %array_ptr.i, align 8, !tbaa !3
  tail call void @free(i8* %1) #1
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  store i64 0, i64* %array_size.i, align 8, !tbaa !0
  store i8* null, i8** %array_ptr.i, align 8, !tbaa !3
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_clear_char(%struct.array_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i8** %array_ptr.i, align 8, !tbaa !3
  tail call void @free(i8* %1) #1
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  store i64 0, i64* %array_size.i, align 8, !tbaa !0
  store i8* null, i8** %array_ptr.i, align 8, !tbaa !3
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  ret void
}

; Function Attrs: nounwind uwtable
define void @array_clear_string(%struct.array_table* %table, i64 %id) #0 {
entry:
  %tobool.i = icmp eq %struct.array_table* %table, null
  br i1 %tobool.i, label %array_clear.exit, label %if.end.i

if.end.i:                                         ; preds = %entry
  %head.i.i = getelementptr inbounds %struct.array_table* %table, i64 0, i32 0
  %current.03.i.i = load %struct.array_descriptor** %head.i.i, align 8
  %tobool4.i.i = icmp eq %struct.array_descriptor* %current.03.i.i, null
  br i1 %tobool4.i.i, label %array_clear.exit, label %while.body.i.i

while.cond.i.i:                                   ; preds = %while.body.i.i
  %next.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 5
  %current.0.i.i = load %struct.array_descriptor** %next.i.i, align 8
  %tobool.i.i = icmp eq %struct.array_descriptor* %current.0.i.i, null
  br i1 %tobool.i.i, label %array_clear.exit, label %while.body.i.i

while.body.i.i:                                   ; preds = %if.end.i, %while.cond.i.i
  %current.05.i.i = phi %struct.array_descriptor* [ %current.0.i.i, %while.cond.i.i ], [ %current.03.i.i, %if.end.i ]
  %array_id.i.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 0
  %0 = load i64* %array_id.i.i, align 8, !tbaa !0
  %cmp.i.i = icmp eq i64 %0, %id
  br i1 %cmp.i.i, label %if.end3.i, label %while.cond.i.i

if.end3.i:                                        ; preds = %while.body.i.i
  %array_ptr.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 3
  %1 = load i8** %array_ptr.i, align 8, !tbaa !3
  tail call void @free(i8* %1) #1
  %array_size.i = getelementptr inbounds %struct.array_descriptor* %current.05.i.i, i64 0, i32 1
  store i64 0, i64* %array_size.i, align 8, !tbaa !0
  store i8* null, i8** %array_ptr.i, align 8, !tbaa !3
  br label %array_clear.exit

array_clear.exit:                                 ; preds = %while.cond.i.i, %entry, %if.end.i, %if.end3.i
  ret void
}

; Function Attrs: nounwind
declare void @llvm.memmove.p0i8.p0i8.i64(i8* nocapture, i8* nocapture, i64, i32, i1) #1

; Function Attrs: nounwind
declare noalias i8* @realloc(i8* nocapture, i64) #3

; Function Attrs: noreturn nounwind
declare void @exit(i32) #4

; Function Attrs: nounwind
declare i64 @fwrite(i8* nocapture, i64, i64, %struct._IO_FILE* nocapture) #1

; Function Attrs: nounwind
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) #1

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind }
attributes #2 = { nounwind readonly uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { noreturn nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="false" "no-frame-pointer-elim-non-leaf"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #5 = { noreturn nounwind }

!0 = metadata !{metadata !"long", metadata !1}
!1 = metadata !{metadata !"omnipotent char", metadata !2}
!2 = metadata !{metadata !"Simple C/C++ TBAA"}
!3 = metadata !{metadata !"any pointer", metadata !1}
!4 = metadata !{metadata !"int", metadata !1}
!5 = metadata !{metadata !"float", metadata !1}
!6 = metadata !{metadata !"_Bool", metadata !1}
!7 = metadata !{i8 0, i8 2}
