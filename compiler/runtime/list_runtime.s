; ModuleID = 'list_runtime.c'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v64:64:64-v128:128:128-a0:0:64-s0:64:64-f80:128:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%struct._IO_FILE = type { i32, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, i8*, %struct._IO_marker*, %struct._IO_FILE*, i32, i32, i64, i16, i8, [1 x i8], i8*, i64, i8*, i8*, i8*, i8*, i64, i32, [20 x i8] }
%struct._IO_marker = type { %struct._IO_marker*, %struct._IO_FILE*, i32 }
%struct.list_table = type { %struct.list_descriptor* }
%struct.list_descriptor = type { %struct.node_t*, %struct.node_t*, i64, i64, i64, i64, %struct.list_descriptor* }
%struct.node_t = type { i8*, %struct.node_t*, %struct.node_t* }

@bytes_per_type = global [5 x i64] [i64 4, i64 4, i64 1, i64 1, i64 8], align 16
@stderr = external global %struct._IO_FILE*
@.str = private unnamed_addr constant [50 x i8] c"Memory allocation failure in `create_list_table`\0A\00", align 1
@.str1 = private unnamed_addr constant [45 x i8] c"Out of range error in `insert_list_element`\0A\00", align 1
@.str2 = private unnamed_addr constant [44 x i8] c"Memory allocation failure in `create_node`\0A\00", align 1
@.str3 = private unnamed_addr constant [42 x i8] c"Memory allocation failure in `cpy_value`\0A\00", align 1
@.str4 = private unnamed_addr constant [45 x i8] c"Out of range error in `remove_list_element`\0A\00", align 1
@.str5 = private unnamed_addr constant [42 x i8] c"Out of range error in `get_list_element`\0A\00", align 1
@list_counter = internal global i64 1, align 8
@.str6 = private unnamed_addr constant [50 x i8] c"Memory allocation failure in `create_descriptor`\0A\00", align 1

; Function Attrs: nounwind uwtable
define %struct.list_table* @create_list_table() #0 {
entry:
  %table = alloca %struct.list_table*, align 8
  %call = call noalias i8* @malloc(i64 8) #4
  %0 = bitcast i8* %call to %struct.list_table*
  store %struct.list_table* %0, %struct.list_table** %table, align 8
  %1 = load %struct.list_table** %table, align 8
  %tobool = icmp ne %struct.list_table* %1, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %2 = load %struct._IO_FILE** @stderr, align 8
  %call1 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %2, i8* getelementptr inbounds ([50 x i8]* @.str, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

if.end:                                           ; preds = %entry
  %3 = load %struct.list_table** %table, align 8
  %head = getelementptr inbounds %struct.list_table* %3, i32 0, i32 0
  store %struct.list_descriptor* null, %struct.list_descriptor** %head, align 8
  %4 = load %struct.list_table** %table, align 8
  ret %struct.list_table* %4
}

; Function Attrs: nounwind
declare noalias i8* @malloc(i64) #1

declare i32 @fprintf(%struct._IO_FILE*, i8*, ...) #2

; Function Attrs: noreturn nounwind
declare void @exit(i32) #3

; Function Attrs: nounwind uwtable
define void @delete_list_table(%struct.list_table* %table) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %current = alloca %struct.list_descriptor*, align 8
  %next = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %head = getelementptr inbounds %struct.list_table* %1, i32 0, i32 0
  %2 = load %struct.list_descriptor** %head, align 8
  store %struct.list_descriptor* %2, %struct.list_descriptor** %current, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.end
  %3 = load %struct.list_descriptor** %current, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %4 = load %struct.list_descriptor** %current, align 8
  %next2 = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 6
  %5 = load %struct.list_descriptor** %next2, align 8
  store %struct.list_descriptor* %5, %struct.list_descriptor** %next, align 8
  %6 = load %struct.list_descriptor** %current, align 8
  call void @free_descriptor(%struct.list_descriptor* %6)
  %7 = load %struct.list_descriptor** %next, align 8
  store %struct.list_descriptor* %7, %struct.list_descriptor** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %8 = load %struct.list_table** %table.addr, align 8
  %9 = bitcast %struct.list_table* %8 to i8*
  call void @free(i8* %9) #4
  br label %return

return:                                           ; preds = %while.end, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @free_descriptor(%struct.list_descriptor* %desc) #0 {
entry:
  %desc.addr = alloca %struct.list_descriptor*, align 8
  %current = alloca %struct.node_t*, align 8
  %next = alloca %struct.node_t*, align 8
  store %struct.list_descriptor* %desc, %struct.list_descriptor** %desc.addr, align 8
  %0 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head = getelementptr inbounds %struct.list_descriptor* %0, i32 0, i32 0
  %1 = load %struct.node_t** %list_head, align 8
  store %struct.node_t* %1, %struct.node_t** %current, align 8
  br label %while.cond

while.cond:                                       ; preds = %while.body, %entry
  %2 = load %struct.node_t** %current, align 8
  %tobool = icmp ne %struct.node_t* %2, null
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %3 = load %struct.node_t** %current, align 8
  %next1 = getelementptr inbounds %struct.node_t* %3, i32 0, i32 1
  %4 = load %struct.node_t** %next1, align 8
  store %struct.node_t* %4, %struct.node_t** %next, align 8
  %5 = load %struct.node_t** %current, align 8
  call void @free_node(%struct.node_t* %5)
  %6 = load %struct.node_t** %next, align 8
  store %struct.node_t* %6, %struct.node_t** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %7 = load %struct.list_descriptor** %desc.addr, align 8
  %8 = bitcast %struct.list_descriptor* %7 to i8*
  call void @free(i8* %8) #4
  ret void
}

; Function Attrs: nounwind
declare void @free(i8*) #1

; Function Attrs: nounwind uwtable
define i64 @list_size(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 3
  %5 = load i64* %list_size, align 8
  store i64 %5, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %6 = load i64* %retval
  ret i64 %6
}

; Function Attrs: nounwind uwtable
define internal %struct.list_descriptor* @find_descriptor(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca %struct.list_descriptor*, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %current = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %head = getelementptr inbounds %struct.list_table* %0, i32 0, i32 0
  %1 = load %struct.list_descriptor** %head, align 8
  store %struct.list_descriptor* %1, %struct.list_descriptor** %current, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end, %entry
  %2 = load %struct.list_descriptor** %current, align 8
  %tobool = icmp ne %struct.list_descriptor* %2, null
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %3 = load %struct.list_descriptor** %current, align 8
  %list_id = getelementptr inbounds %struct.list_descriptor* %3, i32 0, i32 2
  %4 = load i64* %list_id, align 8
  %5 = load i64* %lid.addr, align 8
  %cmp = icmp eq i64 %4, %5
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %while.body
  %6 = load %struct.list_descriptor** %current, align 8
  store %struct.list_descriptor* %6, %struct.list_descriptor** %retval
  br label %return

if.end:                                           ; preds = %while.body
  %7 = load %struct.list_descriptor** %current, align 8
  %next = getelementptr inbounds %struct.list_descriptor* %7, i32 0, i32 6
  %8 = load %struct.list_descriptor** %next, align 8
  store %struct.list_descriptor* %8, %struct.list_descriptor** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  store %struct.list_descriptor* null, %struct.list_descriptor** %retval
  br label %return

return:                                           ; preds = %while.end, %if.then
  %9 = load %struct.list_descriptor** %retval
  ret %struct.list_descriptor* %9
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_empty(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %1 = load i64* %lid.addr, align 8
  %call = call i64 @list_size(%struct.list_table* %0, i64 %1)
  %cmp = icmp eq i64 %call, 0
  ret i1 %cmp
}

; Function Attrs: nounwind uwtable
define void @list_clear(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %list_head = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 0
  %5 = load %struct.node_t** %list_head, align 8
  %tobool4 = icmp ne %struct.node_t* %5, null
  br i1 %tobool4, label %if.end6, label %if.then5

if.then5:                                         ; preds = %if.end3
  br label %return

if.end6:                                          ; preds = %if.end3
  %6 = load %struct.list_descriptor** %desc, align 8
  %list_head7 = getelementptr inbounds %struct.list_descriptor* %6, i32 0, i32 0
  %7 = load %struct.node_t** %list_head7, align 8
  %call8 = call %struct.node_t* @free_node_recur(%struct.node_t* %7)
  %8 = load %struct.list_descriptor** %desc, align 8
  %list_tail = getelementptr inbounds %struct.list_descriptor* %8, i32 0, i32 1
  store %struct.node_t* %call8, %struct.node_t** %list_tail, align 8
  %9 = load %struct.list_descriptor** %desc, align 8
  %list_head9 = getelementptr inbounds %struct.list_descriptor* %9, i32 0, i32 0
  store %struct.node_t* %call8, %struct.node_t** %list_head9, align 8
  %10 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %10, i32 0, i32 3
  store i64 0, i64* %list_size, align 8
  br label %return

return:                                           ; preds = %if.end6, %if.then5, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define internal %struct.node_t* @free_node_recur(%struct.node_t* %node) #0 {
entry:
  %node.addr = alloca %struct.node_t*, align 8
  %prev = alloca %struct.node_t*, align 8
  %next3 = alloca %struct.node_t*, align 8
  store %struct.node_t* %node, %struct.node_t** %node.addr, align 8
  %0 = load %struct.node_t** %node.addr, align 8
  %prev1 = getelementptr inbounds %struct.node_t* %0, i32 0, i32 2
  %1 = load %struct.node_t** %prev1, align 8
  store %struct.node_t* %1, %struct.node_t** %prev, align 8
  %2 = load %struct.node_t** %prev, align 8
  %tobool = icmp ne %struct.node_t* %2, null
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %3 = load %struct.node_t** %prev, align 8
  %next = getelementptr inbounds %struct.node_t* %3, i32 0, i32 1
  store %struct.node_t* null, %struct.node_t** %next, align 8
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  br label %while.cond

while.cond:                                       ; preds = %while.body, %if.end
  %4 = load %struct.node_t** %node.addr, align 8
  %tobool2 = icmp ne %struct.node_t* %4, null
  br i1 %tobool2, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %5 = load %struct.node_t** %node.addr, align 8
  %next4 = getelementptr inbounds %struct.node_t* %5, i32 0, i32 1
  %6 = load %struct.node_t** %next4, align 8
  store %struct.node_t* %6, %struct.node_t** %next3, align 8
  %7 = load %struct.node_t** %node.addr, align 8
  call void @free_node(%struct.node_t* %7)
  %8 = load %struct.node_t** %next3, align 8
  store %struct.node_t* %8, %struct.node_t** %node.addr, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  %9 = load %struct.node_t** %prev, align 8
  ret %struct.node_t* %9
}

; Function Attrs: nounwind uwtable
define void @list_add_reference(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %ref_count = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 4
  %5 = load i64* %ref_count, align 8
  %inc = add i64 %5, 1
  store i64 %inc, i64* %ref_count, align 8
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_rm_reference(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %if.end6

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %if.end6

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %ref_count = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 4
  %5 = load i64* %ref_count, align 8
  %dec = add i64 %5, -1
  store i64 %dec, i64* %ref_count, align 8
  %6 = load %struct.list_descriptor** %desc, align 8
  %ref_count4 = getelementptr inbounds %struct.list_descriptor* %6, i32 0, i32 4
  %7 = load i64* %ref_count4, align 8
  %cmp = icmp eq i64 %7, 0
  br i1 %cmp, label %if.then5, label %if.end6

if.then5:                                         ; preds = %if.end3
  %8 = load %struct.list_table** %table.addr, align 8
  %9 = load i64* %lid.addr, align 8
  call void @list_deallocate(%struct.list_table* %8, i64 %9)
  br label %if.end6

if.end6:                                          ; preds = %if.then, %if.then2, %if.then5, %if.end3
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_deallocate(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %current = alloca %struct.list_descriptor*, align 8
  %prev = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %while.end

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %head = getelementptr inbounds %struct.list_table* %1, i32 0, i32 0
  %2 = load %struct.list_descriptor** %head, align 8
  store %struct.list_descriptor* %2, %struct.list_descriptor** %current, align 8
  store %struct.list_descriptor* null, %struct.list_descriptor** %prev, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end9, %if.end
  %3 = load %struct.list_descriptor** %current, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %4 = load %struct.list_descriptor** %current, align 8
  %list_id = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 2
  %5 = load i64* %list_id, align 8
  %6 = load i64* %lid.addr, align 8
  %cmp = icmp eq i64 %5, %6
  br i1 %cmp, label %if.then2, label %if.end9

if.then2:                                         ; preds = %while.body
  %7 = load %struct.list_descriptor** %prev, align 8
  %tobool3 = icmp ne %struct.list_descriptor* %7, null
  br i1 %tobool3, label %if.then4, label %if.else

if.then4:                                         ; preds = %if.then2
  %8 = load %struct.list_descriptor** %current, align 8
  %next = getelementptr inbounds %struct.list_descriptor* %8, i32 0, i32 6
  %9 = load %struct.list_descriptor** %next, align 8
  %10 = load %struct.list_descriptor** %prev, align 8
  %next5 = getelementptr inbounds %struct.list_descriptor* %10, i32 0, i32 6
  store %struct.list_descriptor* %9, %struct.list_descriptor** %next5, align 8
  br label %if.end8

if.else:                                          ; preds = %if.then2
  %11 = load %struct.list_descriptor** %current, align 8
  %next6 = getelementptr inbounds %struct.list_descriptor* %11, i32 0, i32 6
  %12 = load %struct.list_descriptor** %next6, align 8
  %13 = load %struct.list_table** %table.addr, align 8
  %head7 = getelementptr inbounds %struct.list_table* %13, i32 0, i32 0
  store %struct.list_descriptor* %12, %struct.list_descriptor** %head7, align 8
  br label %if.end8

if.end8:                                          ; preds = %if.else, %if.then4
  %14 = load %struct.list_descriptor** %current, align 8
  call void @free_descriptor(%struct.list_descriptor* %14)
  br label %while.end

if.end9:                                          ; preds = %while.body
  %15 = load %struct.list_descriptor** %current, align 8
  store %struct.list_descriptor* %15, %struct.list_descriptor** %prev, align 8
  %16 = load %struct.list_descriptor** %current, align 8
  %next10 = getelementptr inbounds %struct.list_descriptor* %16, i32 0, i32 6
  %17 = load %struct.list_descriptor** %next10, align 8
  store %struct.list_descriptor* %17, %struct.list_descriptor** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %if.then, %if.end8, %while.cond
  ret void
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_int(%struct.list_table* %table) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @unique_desc_id()
  %call1 = call %struct.list_descriptor* @create_descriptor(i64 %call, i64 0)
  store %struct.list_descriptor* %call1, %struct.list_descriptor** %desc, align 8
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load %struct.list_descriptor** %desc, align 8
  call void @insert_descriptor(%struct.list_table* %1, %struct.list_descriptor* %2)
  %3 = load %struct.list_descriptor** %desc, align 8
  %list_id = getelementptr inbounds %struct.list_descriptor* %3, i32 0, i32 2
  %4 = load i64* %list_id, align 8
  store i64 %4, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %5 = load i64* %retval
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define internal %struct.list_descriptor* @create_descriptor(i64 %lid, i64 %type) #0 {
entry:
  %lid.addr = alloca i64, align 8
  %type.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %type, i64* %type.addr, align 8
  %call = call noalias i8* @malloc(i64 56) #4
  %0 = bitcast i8* %call to %struct.list_descriptor*
  store %struct.list_descriptor* %0, %struct.list_descriptor** %desc, align 8
  %1 = load %struct.list_descriptor** %desc, align 8
  %tobool = icmp ne %struct.list_descriptor* %1, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %2 = load %struct._IO_FILE** @stderr, align 8
  %call1 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %2, i8* getelementptr inbounds ([50 x i8]* @.str6, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

if.end:                                           ; preds = %entry
  %3 = load i64* %lid.addr, align 8
  %4 = load %struct.list_descriptor** %desc, align 8
  %list_id = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 2
  store i64 %3, i64* %list_id, align 8
  %5 = load i64* %type.addr, align 8
  %6 = load %struct.list_descriptor** %desc, align 8
  %type2 = getelementptr inbounds %struct.list_descriptor* %6, i32 0, i32 5
  store i64 %5, i64* %type2, align 8
  %7 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %7, i32 0, i32 3
  store i64 0, i64* %list_size, align 8
  %8 = load %struct.list_descriptor** %desc, align 8
  %ref_count = getelementptr inbounds %struct.list_descriptor* %8, i32 0, i32 4
  store i64 0, i64* %ref_count, align 8
  %9 = load %struct.list_descriptor** %desc, align 8
  %list_tail = getelementptr inbounds %struct.list_descriptor* %9, i32 0, i32 1
  store %struct.node_t* null, %struct.node_t** %list_tail, align 8
  %10 = load %struct.list_descriptor** %desc, align 8
  %list_head = getelementptr inbounds %struct.list_descriptor* %10, i32 0, i32 0
  store %struct.node_t* null, %struct.node_t** %list_head, align 8
  %11 = load %struct.list_descriptor** %desc, align 8
  %next = getelementptr inbounds %struct.list_descriptor* %11, i32 0, i32 6
  store %struct.list_descriptor* null, %struct.list_descriptor** %next, align 8
  %12 = load %struct.list_descriptor** %desc, align 8
  ret %struct.list_descriptor* %12
}

; Function Attrs: nounwind uwtable
define internal void @insert_descriptor(%struct.list_table* %table, %struct.list_descriptor* %desc) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %desc.addr = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store %struct.list_descriptor* %desc, %struct.list_descriptor** %desc.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %head = getelementptr inbounds %struct.list_table* %0, i32 0, i32 0
  %1 = load %struct.list_descriptor** %head, align 8
  %2 = load %struct.list_descriptor** %desc.addr, align 8
  %next = getelementptr inbounds %struct.list_descriptor* %2, i32 0, i32 6
  store %struct.list_descriptor* %1, %struct.list_descriptor** %next, align 8
  %3 = load %struct.list_descriptor** %desc.addr, align 8
  %4 = load %struct.list_table** %table.addr, align 8
  %head1 = getelementptr inbounds %struct.list_table* %4, i32 0, i32 0
  store %struct.list_descriptor* %3, %struct.list_descriptor** %head1, align 8
  ret void
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_float(%struct.list_table* %table) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @unique_desc_id()
  %call1 = call %struct.list_descriptor* @create_descriptor(i64 %call, i64 1)
  store %struct.list_descriptor* %call1, %struct.list_descriptor** %desc, align 8
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load %struct.list_descriptor** %desc, align 8
  call void @insert_descriptor(%struct.list_table* %1, %struct.list_descriptor* %2)
  %3 = load %struct.list_descriptor** %desc, align 8
  %list_id = getelementptr inbounds %struct.list_descriptor* %3, i32 0, i32 2
  %4 = load i64* %list_id, align 8
  store i64 %4, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %5 = load i64* %retval
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_bool(%struct.list_table* %table) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @unique_desc_id()
  %call1 = call %struct.list_descriptor* @create_descriptor(i64 %call, i64 2)
  store %struct.list_descriptor* %call1, %struct.list_descriptor** %desc, align 8
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load %struct.list_descriptor** %desc, align 8
  call void @insert_descriptor(%struct.list_table* %1, %struct.list_descriptor* %2)
  %3 = load %struct.list_descriptor** %desc, align 8
  %list_id = getelementptr inbounds %struct.list_descriptor* %3, i32 0, i32 2
  %4 = load i64* %list_id, align 8
  store i64 %4, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %5 = load i64* %retval
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_char(%struct.list_table* %table) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @unique_desc_id()
  %call1 = call %struct.list_descriptor* @create_descriptor(i64 %call, i64 3)
  store %struct.list_descriptor* %call1, %struct.list_descriptor** %desc, align 8
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load %struct.list_descriptor** %desc, align 8
  call void @insert_descriptor(%struct.list_table* %1, %struct.list_descriptor* %2)
  %3 = load %struct.list_descriptor** %desc, align 8
  %list_id = getelementptr inbounds %struct.list_descriptor* %3, i32 0, i32 2
  %4 = load i64* %list_id, align 8
  store i64 %4, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %5 = load i64* %retval
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define i64 @list_allocate_string(%struct.list_table* %table) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %call = call i64 @unique_desc_id()
  %call1 = call %struct.list_descriptor* @create_descriptor(i64 %call, i64 4)
  store %struct.list_descriptor* %call1, %struct.list_descriptor** %desc, align 8
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load %struct.list_descriptor** %desc, align 8
  call void @insert_descriptor(%struct.list_table* %1, %struct.list_descriptor* %2)
  %3 = load %struct.list_descriptor** %desc, align 8
  %list_id = getelementptr inbounds %struct.list_descriptor* %3, i32 0, i32 2
  %4 = load i64* %list_id, align 8
  store i64 %4, i64* %retval
  br label %return

return:                                           ; preds = %if.end, %if.then
  %5 = load i64* %retval
  ret i64 %5
}

; Function Attrs: nounwind uwtable
define i32 @list_front_int(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = bitcast i8* %5 to i32*
  %7 = load i32* %6, align 4
  store i32 %7, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %8 = load i32* %retval
  ret i32 %8
}

; Function Attrs: nounwind uwtable
define internal i8* @get_list_element(%struct.list_descriptor* %desc, i64 %pos) #0 {
entry:
  %retval = alloca i8*, align 8
  %desc.addr = alloca %struct.list_descriptor*, align 8
  %pos.addr = alloca i64, align 8
  %current = alloca %struct.node_t*, align 8
  %cnt = alloca i64, align 8
  store %struct.list_descriptor* %desc, %struct.list_descriptor** %desc.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load i64* %pos.addr, align 8
  %1 = load %struct.list_descriptor** %desc.addr, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %1, i32 0, i32 3
  %2 = load i64* %list_size, align 8
  %cmp = icmp uge i64 %0, %2
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %3 = load %struct._IO_FILE** @stderr, align 8
  %call = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([42 x i8]* @.str5, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

if.end:                                           ; preds = %entry
  %4 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 0
  %5 = load %struct.node_t** %list_head, align 8
  store %struct.node_t* %5, %struct.node_t** %current, align 8
  store i64 0, i64* %cnt, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end3, %if.end
  %6 = load %struct.node_t** %current, align 8
  %tobool = icmp ne %struct.node_t* %6, null
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %7 = load i64* %cnt, align 8
  %inc = add i64 %7, 1
  store i64 %inc, i64* %cnt, align 8
  %8 = load i64* %pos.addr, align 8
  %cmp1 = icmp eq i64 %7, %8
  br i1 %cmp1, label %if.then2, label %if.end3

if.then2:                                         ; preds = %while.body
  %9 = load %struct.node_t** %current, align 8
  %value = getelementptr inbounds %struct.node_t* %9, i32 0, i32 0
  %10 = load i8** %value, align 8
  store i8* %10, i8** %retval
  br label %return

if.end3:                                          ; preds = %while.body
  %11 = load %struct.node_t** %current, align 8
  %next = getelementptr inbounds %struct.node_t* %11, i32 0, i32 1
  %12 = load %struct.node_t** %next, align 8
  store %struct.node_t* %12, %struct.node_t** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  store i8* null, i8** %retval
  br label %return

return:                                           ; preds = %while.end, %if.then2
  %13 = load i8** %retval
  ret i8* %13
}

; Function Attrs: nounwind uwtable
define float @list_front_float(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = bitcast i8* %5 to float*
  %7 = load float* %6, align 4
  store float %7, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %8 = load float* %retval
  ret float %8
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_front_bool(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = load i8* %5, align 1
  %tobool5 = trunc i8 %6 to i1
  store i1 %tobool5, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %7 = load i1* %retval
  ret i1 %7
}

; Function Attrs: nounwind uwtable
define signext i8 @list_front_char(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = load i8* %5, align 1
  store i8 %6, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %7 = load i8* %retval
  ret i8 %7
}

; Function Attrs: nounwind uwtable
define i64 @list_front_string(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = bitcast i8* %5 to i64*
  %7 = load i64* %6, align 8
  store i64 %7, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %8 = load i64* %retval
  ret i64 %8
}

; Function Attrs: nounwind uwtable
define i32 @list_back_int(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = bitcast i8* %7 to i32*
  %9 = load i32* %8, align 4
  store i32 %9, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load i32* %retval
  ret i32 %10
}

; Function Attrs: nounwind uwtable
define float @list_back_float(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = bitcast i8* %7 to float*
  %9 = load float* %8, align 4
  store float %9, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load float* %retval
  ret float %10
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_back_bool(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = load i8* %7, align 1
  %tobool5 = trunc i8 %8 to i1
  store i1 %tobool5, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load i1* %retval
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define signext i8 @list_back_char(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = load i8* %7, align 1
  store i8 %8, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load i8* %retval
  ret i8 %9
}

; Function Attrs: nounwind uwtable
define i64 @list_back_string(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = bitcast i8* %7 to i64*
  %9 = load i64* %8, align 8
  store i64 %9, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load i64* %retval
  ret i64 %10
}

; Function Attrs: nounwind uwtable
define i32 @list_pop_front_int(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i32, align 4
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = bitcast i8* %5 to i32*
  %7 = load i32* %6, align 4
  store i32 %7, i32* %casted_value, align 4
  %8 = load i8** %value, align 8
  call void @free(i8* %8) #4
  %9 = load i32* %casted_value, align 4
  store i32 %9, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load i32* %retval
  ret i32 %10
}

; Function Attrs: nounwind uwtable
define internal i8* @remove_list_element(%struct.list_descriptor* %desc, i64 %pos) #0 {
entry:
  %retval = alloca i8*, align 8
  %desc.addr = alloca %struct.list_descriptor*, align 8
  %pos.addr = alloca i64, align 8
  %current = alloca %struct.node_t*, align 8
  %cnt = alloca i64, align 8
  %new_value = alloca i8*, align 8
  store %struct.list_descriptor* %desc, %struct.list_descriptor** %desc.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load i64* %pos.addr, align 8
  %1 = load %struct.list_descriptor** %desc.addr, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %1, i32 0, i32 3
  %2 = load i64* %list_size, align 8
  %cmp = icmp uge i64 %0, %2
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %3 = load %struct._IO_FILE** @stderr, align 8
  %call = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([45 x i8]* @.str4, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

if.end:                                           ; preds = %entry
  %4 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head = getelementptr inbounds %struct.list_descriptor* %4, i32 0, i32 0
  %5 = load %struct.node_t** %list_head, align 8
  store %struct.node_t* %5, %struct.node_t** %current, align 8
  store i64 0, i64* %cnt, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end36, %if.end
  %6 = load %struct.node_t** %current, align 8
  %tobool = icmp ne %struct.node_t* %6, null
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %7 = load i64* %cnt, align 8
  %inc = add i64 %7, 1
  store i64 %inc, i64* %cnt, align 8
  %8 = load i64* %pos.addr, align 8
  %cmp1 = icmp eq i64 %7, %8
  br i1 %cmp1, label %if.then2, label %if.end36

if.then2:                                         ; preds = %while.body
  %9 = load %struct.node_t** %current, align 8
  %next = getelementptr inbounds %struct.node_t* %9, i32 0, i32 1
  %10 = load %struct.node_t** %next, align 8
  %tobool3 = icmp ne %struct.node_t* %10, null
  br i1 %tobool3, label %land.lhs.true, label %if.else

land.lhs.true:                                    ; preds = %if.then2
  %11 = load %struct.node_t** %current, align 8
  %prev = getelementptr inbounds %struct.node_t* %11, i32 0, i32 2
  %12 = load %struct.node_t** %prev, align 8
  %tobool4 = icmp ne %struct.node_t* %12, null
  br i1 %tobool4, label %if.then5, label %if.else

if.then5:                                         ; preds = %land.lhs.true
  %13 = load %struct.node_t** %current, align 8
  %next6 = getelementptr inbounds %struct.node_t* %13, i32 0, i32 1
  %14 = load %struct.node_t** %next6, align 8
  %15 = load %struct.node_t** %current, align 8
  %prev7 = getelementptr inbounds %struct.node_t* %15, i32 0, i32 2
  %16 = load %struct.node_t** %prev7, align 8
  %next8 = getelementptr inbounds %struct.node_t* %16, i32 0, i32 1
  store %struct.node_t* %14, %struct.node_t** %next8, align 8
  %17 = load %struct.node_t** %current, align 8
  %prev9 = getelementptr inbounds %struct.node_t* %17, i32 0, i32 2
  %18 = load %struct.node_t** %prev9, align 8
  %19 = load %struct.node_t** %current, align 8
  %next10 = getelementptr inbounds %struct.node_t* %19, i32 0, i32 1
  %20 = load %struct.node_t** %next10, align 8
  %prev11 = getelementptr inbounds %struct.node_t* %20, i32 0, i32 2
  store %struct.node_t* %18, %struct.node_t** %prev11, align 8
  br label %if.end33

if.else:                                          ; preds = %land.lhs.true, %if.then2
  %21 = load %struct.node_t** %current, align 8
  %next12 = getelementptr inbounds %struct.node_t* %21, i32 0, i32 1
  %22 = load %struct.node_t** %next12, align 8
  %tobool13 = icmp ne %struct.node_t* %22, null
  br i1 %tobool13, label %if.then14, label %if.else20

if.then14:                                        ; preds = %if.else
  %23 = load %struct.node_t** %current, align 8
  %next15 = getelementptr inbounds %struct.node_t* %23, i32 0, i32 1
  %24 = load %struct.node_t** %next15, align 8
  %25 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head16 = getelementptr inbounds %struct.list_descriptor* %25, i32 0, i32 0
  store %struct.node_t* %24, %struct.node_t** %list_head16, align 8
  %26 = load %struct.node_t** %current, align 8
  %prev17 = getelementptr inbounds %struct.node_t* %26, i32 0, i32 2
  %27 = load %struct.node_t** %prev17, align 8
  %28 = load %struct.node_t** %current, align 8
  %next18 = getelementptr inbounds %struct.node_t* %28, i32 0, i32 1
  %29 = load %struct.node_t** %next18, align 8
  %prev19 = getelementptr inbounds %struct.node_t* %29, i32 0, i32 2
  store %struct.node_t* %27, %struct.node_t** %prev19, align 8
  br label %if.end32

if.else20:                                        ; preds = %if.else
  %30 = load %struct.node_t** %current, align 8
  %prev21 = getelementptr inbounds %struct.node_t* %30, i32 0, i32 2
  %31 = load %struct.node_t** %prev21, align 8
  %tobool22 = icmp ne %struct.node_t* %31, null
  br i1 %tobool22, label %if.then23, label %if.else28

if.then23:                                        ; preds = %if.else20
  %32 = load %struct.node_t** %current, align 8
  %prev24 = getelementptr inbounds %struct.node_t* %32, i32 0, i32 2
  %33 = load %struct.node_t** %prev24, align 8
  %34 = load %struct.list_descriptor** %desc.addr, align 8
  %list_tail = getelementptr inbounds %struct.list_descriptor* %34, i32 0, i32 1
  store %struct.node_t* %33, %struct.node_t** %list_tail, align 8
  %35 = load %struct.node_t** %current, align 8
  %next25 = getelementptr inbounds %struct.node_t* %35, i32 0, i32 1
  %36 = load %struct.node_t** %next25, align 8
  %37 = load %struct.node_t** %current, align 8
  %prev26 = getelementptr inbounds %struct.node_t* %37, i32 0, i32 2
  %38 = load %struct.node_t** %prev26, align 8
  %next27 = getelementptr inbounds %struct.node_t* %38, i32 0, i32 1
  store %struct.node_t* %36, %struct.node_t** %next27, align 8
  br label %if.end31

if.else28:                                        ; preds = %if.else20
  %39 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head29 = getelementptr inbounds %struct.list_descriptor* %39, i32 0, i32 0
  store %struct.node_t* null, %struct.node_t** %list_head29, align 8
  %40 = load %struct.list_descriptor** %desc.addr, align 8
  %list_tail30 = getelementptr inbounds %struct.list_descriptor* %40, i32 0, i32 1
  store %struct.node_t* null, %struct.node_t** %list_tail30, align 8
  br label %if.end31

if.end31:                                         ; preds = %if.else28, %if.then23
  br label %if.end32

if.end32:                                         ; preds = %if.end31, %if.then14
  br label %if.end33

if.end33:                                         ; preds = %if.end32, %if.then5
  %41 = load %struct.node_t** %current, align 8
  %value = getelementptr inbounds %struct.node_t* %41, i32 0, i32 0
  %42 = load i8** %value, align 8
  %43 = load %struct.list_descriptor** %desc.addr, align 8
  %type = getelementptr inbounds %struct.list_descriptor* %43, i32 0, i32 5
  %44 = load i64* %type, align 8
  %call34 = call i8* @cpy_value(i8* %42, i64 %44)
  store i8* %call34, i8** %new_value, align 8
  %45 = load %struct.node_t** %current, align 8
  call void @free_node(%struct.node_t* %45)
  %46 = load %struct.list_descriptor** %desc.addr, align 8
  %list_size35 = getelementptr inbounds %struct.list_descriptor* %46, i32 0, i32 3
  %47 = load i64* %list_size35, align 8
  %dec = add i64 %47, -1
  store i64 %dec, i64* %list_size35, align 8
  %48 = load i8** %new_value, align 8
  store i8* %48, i8** %retval
  br label %return

if.end36:                                         ; preds = %while.body
  %49 = load %struct.node_t** %current, align 8
  %next37 = getelementptr inbounds %struct.node_t* %49, i32 0, i32 1
  %50 = load %struct.node_t** %next37, align 8
  store %struct.node_t* %50, %struct.node_t** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %while.cond
  store i8* null, i8** %retval
  br label %return

return:                                           ; preds = %while.end, %if.end33
  %51 = load i8** %retval
  ret i8* %51
}

; Function Attrs: nounwind uwtable
define float @list_pop_front_float(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca float, align 4
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = bitcast i8* %5 to float*
  %7 = load float* %6, align 4
  store float %7, float* %casted_value, align 4
  %8 = load i8** %value, align 8
  call void @free(i8* %8) #4
  %9 = load float* %casted_value, align 4
  store float %9, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load float* %retval
  ret float %10
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_pop_front_bool(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i8, align 1
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = load i8* %5, align 1
  %tobool5 = trunc i8 %6 to i1
  %frombool = zext i1 %tobool5 to i8
  store i8 %frombool, i8* %casted_value, align 1
  %7 = load i8** %value, align 8
  call void @free(i8* %7) #4
  %8 = load i8* %casted_value, align 1
  %tobool6 = trunc i8 %8 to i1
  store i1 %tobool6, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load i1* %retval
  ret i1 %9
}

; Function Attrs: nounwind uwtable
define signext i8 @list_pop_front_char(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i8, align 1
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = load i8* %5, align 1
  store i8 %6, i8* %casted_value, align 1
  %7 = load i8** %value, align 8
  call void @free(i8* %7) #4
  %8 = load i8* %casted_value, align 1
  store i8 %8, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load i8* %retval
  ret i8 %9
}

; Function Attrs: nounwind uwtable
define i64 @list_pop_front_string(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i64, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 0)
  store i8* %call4, i8** %value, align 8
  %5 = load i8** %value, align 8
  %6 = bitcast i8* %5 to i64*
  %7 = load i64* %6, align 8
  store i64 %7, i64* %casted_value, align 8
  %8 = load i8** %value, align 8
  call void @free(i8* %8) #4
  %9 = load i64* %casted_value, align 8
  store i64 %9, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load i64* %retval
  ret i64 %10
}

; Function Attrs: nounwind uwtable
define i32 @list_pop_back_int(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i32, align 4
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = bitcast i8* %7 to i32*
  %9 = load i32* %8, align 4
  store i32 %9, i32* %casted_value, align 4
  %10 = load i8** %value, align 8
  call void @free(i8* %10) #4
  %11 = load i32* %casted_value, align 4
  store i32 %11, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %12 = load i32* %retval
  ret i32 %12
}

; Function Attrs: nounwind uwtable
define float @list_pop_back_float(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca float, align 4
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = bitcast i8* %7 to float*
  %9 = load float* %8, align 4
  store float %9, float* %casted_value, align 4
  %10 = load i8** %value, align 8
  call void @free(i8* %10) #4
  %11 = load float* %casted_value, align 4
  store float %11, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %12 = load float* %retval
  ret float %12
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_pop_back_bool(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i8, align 1
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = load i8* %7, align 1
  %tobool5 = trunc i8 %8 to i1
  %frombool = zext i1 %tobool5 to i8
  store i8 %frombool, i8* %casted_value, align 1
  %9 = load i8** %value, align 8
  call void @free(i8* %9) #4
  %10 = load i8* %casted_value, align 1
  %tobool6 = trunc i8 %10 to i1
  store i1 %tobool6, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %11 = load i1* %retval
  ret i1 %11
}

; Function Attrs: nounwind uwtable
define signext i8 @list_pop_back_char(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i8, align 1
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = load i8* %7, align 1
  store i8 %8, i8* %casted_value, align 1
  %9 = load i8** %value, align 8
  call void @free(i8* %9) #4
  %10 = load i8* %casted_value, align 1
  store i8 %10, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %11 = load i8* %retval
  ret i8 %11
}

; Function Attrs: nounwind uwtable
define i64 @list_pop_back_string(%struct.list_table* %table, i64 %lid) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i64, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %sub = sub i64 %6, 1
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %sub)
  store i8* %call4, i8** %value, align 8
  %7 = load i8** %value, align 8
  %8 = bitcast i8* %7 to i64*
  %9 = load i64* %8, align 8
  store i64 %9, i64* %casted_value, align 8
  %10 = load i8** %value, align 8
  call void @free(i8* %10) #4
  %11 = load i64* %casted_value, align 8
  store i64 %11, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %12 = load i64* %retval
  ret i64 %12
}

; Function Attrs: nounwind uwtable
define void @list_push_front_int(%struct.list_table* %table, i64 %lid, i32 %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca i32, align 4
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i32 %value, i32* %value.addr, align 4
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = bitcast i32* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 0, i8* %5)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define internal void @insert_list_element(%struct.list_descriptor* %desc, i64 %pos, i8* %elem) #0 {
entry:
  %desc.addr = alloca %struct.list_descriptor*, align 8
  %pos.addr = alloca i64, align 8
  %elem.addr = alloca i8*, align 8
  %new_node = alloca %struct.node_t*, align 8
  %current = alloca %struct.node_t*, align 8
  %cnt = alloca i64, align 8
  %new_node17 = alloca %struct.node_t*, align 8
  store %struct.list_descriptor* %desc, %struct.list_descriptor** %desc.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  store i8* %elem, i8** %elem.addr, align 8
  %0 = load i64* %pos.addr, align 8
  %1 = load %struct.list_descriptor** %desc.addr, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %1, i32 0, i32 3
  %2 = load i64* %list_size, align 8
  %cmp = icmp ugt i64 %0, %2
  br i1 %cmp, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %3 = load %struct._IO_FILE** @stderr, align 8
  %call = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %3, i8* getelementptr inbounds ([45 x i8]* @.str1, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

if.end:                                           ; preds = %entry
  %4 = load i64* %pos.addr, align 8
  %5 = load %struct.list_descriptor** %desc.addr, align 8
  %list_size1 = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size1, align 8
  %cmp2 = icmp eq i64 %4, %6
  br i1 %cmp2, label %if.then3, label %if.end12

if.then3:                                         ; preds = %if.end
  %7 = load i8** %elem.addr, align 8
  %8 = load %struct.list_descriptor** %desc.addr, align 8
  %type = getelementptr inbounds %struct.list_descriptor* %8, i32 0, i32 5
  %9 = load i64* %type, align 8
  %call4 = call %struct.node_t* @create_node(%struct.node_t* null, %struct.node_t* null, i8* %7, i64 %9)
  store %struct.node_t* %call4, %struct.node_t** %new_node, align 8
  %10 = load %struct.list_descriptor** %desc.addr, align 8
  %list_size5 = getelementptr inbounds %struct.list_descriptor* %10, i32 0, i32 3
  %11 = load i64* %list_size5, align 8
  %cmp6 = icmp eq i64 %11, 0
  br i1 %cmp6, label %if.then7, label %if.else

if.then7:                                         ; preds = %if.then3
  %12 = load %struct.node_t** %new_node, align 8
  %13 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head = getelementptr inbounds %struct.list_descriptor* %13, i32 0, i32 0
  store %struct.node_t* %12, %struct.node_t** %list_head, align 8
  br label %if.end8

if.else:                                          ; preds = %if.then3
  %14 = load %struct.node_t** %new_node, align 8
  %15 = load %struct.list_descriptor** %desc.addr, align 8
  %list_tail = getelementptr inbounds %struct.list_descriptor* %15, i32 0, i32 1
  %16 = load %struct.node_t** %list_tail, align 8
  %next = getelementptr inbounds %struct.node_t* %16, i32 0, i32 1
  store %struct.node_t* %14, %struct.node_t** %next, align 8
  br label %if.end8

if.end8:                                          ; preds = %if.else, %if.then7
  %17 = load %struct.list_descriptor** %desc.addr, align 8
  %list_tail9 = getelementptr inbounds %struct.list_descriptor* %17, i32 0, i32 1
  %18 = load %struct.node_t** %list_tail9, align 8
  %19 = load %struct.node_t** %new_node, align 8
  %prev = getelementptr inbounds %struct.node_t* %19, i32 0, i32 2
  store %struct.node_t* %18, %struct.node_t** %prev, align 8
  %20 = load %struct.node_t** %new_node, align 8
  %21 = load %struct.list_descriptor** %desc.addr, align 8
  %list_tail10 = getelementptr inbounds %struct.list_descriptor* %21, i32 0, i32 1
  store %struct.node_t* %20, %struct.node_t** %list_tail10, align 8
  %22 = load %struct.list_descriptor** %desc.addr, align 8
  %list_size11 = getelementptr inbounds %struct.list_descriptor* %22, i32 0, i32 3
  %23 = load i64* %list_size11, align 8
  %inc = add i64 %23, 1
  store i64 %inc, i64* %list_size11, align 8
  br label %while.end

if.end12:                                         ; preds = %if.end
  %24 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head13 = getelementptr inbounds %struct.list_descriptor* %24, i32 0, i32 0
  %25 = load %struct.node_t** %list_head13, align 8
  store %struct.node_t* %25, %struct.node_t** %current, align 8
  store i64 0, i64* %cnt, align 8
  br label %while.cond

while.cond:                                       ; preds = %if.end45, %if.end12
  %26 = load %struct.node_t** %current, align 8
  %tobool = icmp ne %struct.node_t* %26, null
  br i1 %tobool, label %while.body, label %while.end

while.body:                                       ; preds = %while.cond
  %27 = load i64* %cnt, align 8
  %inc14 = add i64 %27, 1
  store i64 %inc14, i64* %cnt, align 8
  %28 = load i64* %pos.addr, align 8
  %cmp15 = icmp eq i64 %27, %28
  br i1 %cmp15, label %if.then16, label %if.end45

if.then16:                                        ; preds = %while.body
  %29 = load i8** %elem.addr, align 8
  %30 = load %struct.list_descriptor** %desc.addr, align 8
  %type18 = getelementptr inbounds %struct.list_descriptor* %30, i32 0, i32 5
  %31 = load i64* %type18, align 8
  %call19 = call %struct.node_t* @create_node(%struct.node_t* null, %struct.node_t* null, i8* %29, i64 %31)
  store %struct.node_t* %call19, %struct.node_t** %new_node17, align 8
  %32 = load %struct.node_t** %current, align 8
  %prev20 = getelementptr inbounds %struct.node_t* %32, i32 0, i32 2
  %33 = load %struct.node_t** %prev20, align 8
  %tobool21 = icmp ne %struct.node_t* %33, null
  br i1 %tobool21, label %if.then22, label %if.else29

if.then22:                                        ; preds = %if.then16
  %34 = load %struct.node_t** %current, align 8
  %prev23 = getelementptr inbounds %struct.node_t* %34, i32 0, i32 2
  %35 = load %struct.node_t** %prev23, align 8
  %36 = load %struct.node_t** %new_node17, align 8
  %prev24 = getelementptr inbounds %struct.node_t* %36, i32 0, i32 2
  store %struct.node_t* %35, %struct.node_t** %prev24, align 8
  %37 = load %struct.node_t** %current, align 8
  %38 = load %struct.node_t** %new_node17, align 8
  %next25 = getelementptr inbounds %struct.node_t* %38, i32 0, i32 1
  store %struct.node_t* %37, %struct.node_t** %next25, align 8
  %39 = load %struct.node_t** %new_node17, align 8
  %40 = load %struct.node_t** %current, align 8
  %prev26 = getelementptr inbounds %struct.node_t* %40, i32 0, i32 2
  %41 = load %struct.node_t** %prev26, align 8
  %next27 = getelementptr inbounds %struct.node_t* %41, i32 0, i32 1
  store %struct.node_t* %39, %struct.node_t** %next27, align 8
  %42 = load %struct.node_t** %new_node17, align 8
  %43 = load %struct.node_t** %current, align 8
  %prev28 = getelementptr inbounds %struct.node_t* %43, i32 0, i32 2
  store %struct.node_t* %42, %struct.node_t** %prev28, align 8
  br label %if.end42

if.else29:                                        ; preds = %if.then16
  %44 = load %struct.node_t** %current, align 8
  %prev30 = getelementptr inbounds %struct.node_t* %44, i32 0, i32 2
  %45 = load %struct.node_t** %prev30, align 8
  %tobool31 = icmp ne %struct.node_t* %45, null
  br i1 %tobool31, label %if.else38, label %if.then32

if.then32:                                        ; preds = %if.else29
  %46 = load %struct.node_t** %current, align 8
  %prev33 = getelementptr inbounds %struct.node_t* %46, i32 0, i32 2
  %47 = load %struct.node_t** %prev33, align 8
  %48 = load %struct.node_t** %new_node17, align 8
  %prev34 = getelementptr inbounds %struct.node_t* %48, i32 0, i32 2
  store %struct.node_t* %47, %struct.node_t** %prev34, align 8
  %49 = load %struct.node_t** %current, align 8
  %50 = load %struct.node_t** %new_node17, align 8
  %next35 = getelementptr inbounds %struct.node_t* %50, i32 0, i32 1
  store %struct.node_t* %49, %struct.node_t** %next35, align 8
  %51 = load %struct.node_t** %new_node17, align 8
  %52 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head36 = getelementptr inbounds %struct.list_descriptor* %52, i32 0, i32 0
  store %struct.node_t* %51, %struct.node_t** %list_head36, align 8
  %53 = load %struct.node_t** %new_node17, align 8
  %54 = load %struct.node_t** %current, align 8
  %prev37 = getelementptr inbounds %struct.node_t* %54, i32 0, i32 2
  store %struct.node_t* %53, %struct.node_t** %prev37, align 8
  br label %if.end41

if.else38:                                        ; preds = %if.else29
  %55 = load %struct.node_t** %new_node17, align 8
  %56 = load %struct.list_descriptor** %desc.addr, align 8
  %list_head39 = getelementptr inbounds %struct.list_descriptor* %56, i32 0, i32 0
  store %struct.node_t* %55, %struct.node_t** %list_head39, align 8
  %57 = load %struct.list_descriptor** %desc.addr, align 8
  %list_tail40 = getelementptr inbounds %struct.list_descriptor* %57, i32 0, i32 1
  store %struct.node_t* %55, %struct.node_t** %list_tail40, align 8
  br label %if.end41

if.end41:                                         ; preds = %if.else38, %if.then32
  br label %if.end42

if.end42:                                         ; preds = %if.end41, %if.then22
  %58 = load %struct.list_descriptor** %desc.addr, align 8
  %list_size43 = getelementptr inbounds %struct.list_descriptor* %58, i32 0, i32 3
  %59 = load i64* %list_size43, align 8
  %inc44 = add i64 %59, 1
  store i64 %inc44, i64* %list_size43, align 8
  br label %while.end

if.end45:                                         ; preds = %while.body
  %60 = load %struct.node_t** %current, align 8
  %next46 = getelementptr inbounds %struct.node_t* %60, i32 0, i32 1
  %61 = load %struct.node_t** %next46, align 8
  store %struct.node_t* %61, %struct.node_t** %current, align 8
  br label %while.cond

while.end:                                        ; preds = %if.end8, %if.end42, %while.cond
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_front_float(%struct.list_table* %table, i64 %lid, float %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca float, align 4
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store float %value, float* %value.addr, align 4
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = bitcast float* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 0, i8* %5)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_front_bool(%struct.list_table* %table, i64 %lid, i1 zeroext %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  call void @insert_list_element(%struct.list_descriptor* %4, i64 0, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_front_char(%struct.list_table* %table, i64 %lid, i8 signext %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i8 %value, i8* %value.addr, align 1
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  call void @insert_list_element(%struct.list_descriptor* %4, i64 0, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_front_string(%struct.list_table* %table, i64 %lid, i64 %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %value, i64* %value.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = bitcast i64* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 0, i8* %5)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_int(%struct.list_table* %table, i64 %lid, i32 %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca i32, align 4
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i32 %value, i32* %value.addr, align 4
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %7 = bitcast i32* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %6, i8* %7)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_float(%struct.list_table* %table, i64 %lid, float %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca float, align 4
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store float %value, float* %value.addr, align 4
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %7 = bitcast float* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %6, i8* %7)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_bool(%struct.list_table* %table, i64 %lid, i1 zeroext %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %6, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_char(%struct.list_table* %table, i64 %lid, i8 signext %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i8 %value, i8* %value.addr, align 1
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %6, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_push_back_string(%struct.list_table* %table, i64 %lid, i64 %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %value.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %value, i64* %value.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load %struct.list_descriptor** %desc, align 8
  %list_size = getelementptr inbounds %struct.list_descriptor* %5, i32 0, i32 3
  %6 = load i64* %list_size, align 8
  %7 = bitcast i64* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %6, i8* %7)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @list_get_element_int(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = bitcast i8* %6 to i32*
  %8 = load i32* %7, align 4
  store i32 %8, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load i32* %retval
  ret i32 %9
}

; Function Attrs: nounwind uwtable
define float @list_get_element_float(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = bitcast i8* %6 to float*
  %8 = load float* %7, align 4
  store float %8, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load float* %retval
  ret float %9
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_get_element_bool(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = load i8* %6, align 1
  %tobool5 = trunc i8 %7 to i1
  store i1 %tobool5, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %8 = load i1* %retval
  ret i1 %8
}

; Function Attrs: nounwind uwtable
define signext i8 @list_get_element_char(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = load i8* %6, align 1
  store i8 %7, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %8 = load i8* %retval
  ret i8 %8
}

; Function Attrs: nounwind uwtable
define i64 @list_get_element_string(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @get_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = bitcast i8* %6 to i64*
  %8 = load i64* %7, align 8
  store i64 %8, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %9 = load i64* %retval
  ret i64 %9
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_int(%struct.list_table* %table, i64 %lid, i64 %pos, i32 %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %value.addr = alloca i32, align 4
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  store i32 %value, i32* %value.addr, align 4
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %6 = bitcast i32* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %5, i8* %6)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_float(%struct.list_table* %table, i64 %lid, i64 %pos, float %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %value.addr = alloca float, align 4
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  store float %value, float* %value.addr, align 4
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %6 = bitcast float* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %5, i8* %6)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_bool(%struct.list_table* %table, i64 %lid, i64 %pos, i1 zeroext %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %frombool = zext i1 %value to i8
  store i8 %frombool, i8* %value.addr, align 1
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %5, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_char(%struct.list_table* %table, i64 %lid, i64 %pos, i8 signext %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %value.addr = alloca i8, align 1
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  store i8 %value, i8* %value.addr, align 1
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %5, i8* %value.addr)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define void @list_insert_element_string(%struct.list_table* %table, i64 %lid, i64 %pos, i64 %value) #0 {
entry:
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %value.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  store i64 %value, i64* %value.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %6 = bitcast i64* %value.addr to i8*
  call void @insert_list_element(%struct.list_descriptor* %4, i64 %5, i8* %6)
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  ret void
}

; Function Attrs: nounwind uwtable
define i32 @list_remove_element_int(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca i32, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i32, align 4
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i32 0, i32* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i32 0, i32* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = bitcast i8* %6 to i32*
  %8 = load i32* %7, align 4
  store i32 %8, i32* %casted_value, align 4
  %9 = load i8** %value, align 8
  call void @free(i8* %9) #4
  %10 = load i32* %casted_value, align 4
  store i32 %10, i32* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %11 = load i32* %retval
  ret i32 %11
}

; Function Attrs: nounwind uwtable
define float @list_remove_element_float(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca float, align 4
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca float, align 4
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store float 0.000000e+00, float* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store float 0.000000e+00, float* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = bitcast i8* %6 to float*
  %8 = load float* %7, align 4
  store float %8, float* %casted_value, align 4
  %9 = load i8** %value, align 8
  call void @free(i8* %9) #4
  %10 = load float* %casted_value, align 4
  store float %10, float* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %11 = load float* %retval
  ret float %11
}

; Function Attrs: nounwind uwtable
define zeroext i1 @list_remove_element_bool(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca i1, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i8, align 1
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i1 false, i1* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i1 false, i1* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = load i8* %6, align 1
  %tobool5 = trunc i8 %7 to i1
  %frombool = zext i1 %tobool5 to i8
  store i8 %frombool, i8* %casted_value, align 1
  %8 = load i8** %value, align 8
  call void @free(i8* %8) #4
  %9 = load i8* %casted_value, align 1
  %tobool6 = trunc i8 %9 to i1
  store i1 %tobool6, i1* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load i1* %retval
  ret i1 %10
}

; Function Attrs: nounwind uwtable
define signext i8 @list_remove_element_char(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca i8, align 1
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i8, align 1
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i8 0, i8* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i8 0, i8* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = load i8* %6, align 1
  store i8 %7, i8* %casted_value, align 1
  %8 = load i8** %value, align 8
  call void @free(i8* %8) #4
  %9 = load i8* %casted_value, align 1
  store i8 %9, i8* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %10 = load i8* %retval
  ret i8 %10
}

; Function Attrs: nounwind uwtable
define i64 @list_remove_element_string(%struct.list_table* %table, i64 %lid, i64 %pos) #0 {
entry:
  %retval = alloca i64, align 8
  %table.addr = alloca %struct.list_table*, align 8
  %lid.addr = alloca i64, align 8
  %pos.addr = alloca i64, align 8
  %desc = alloca %struct.list_descriptor*, align 8
  %value = alloca i8*, align 8
  %casted_value = alloca i64, align 8
  store %struct.list_table* %table, %struct.list_table** %table.addr, align 8
  store i64 %lid, i64* %lid.addr, align 8
  store i64 %pos, i64* %pos.addr, align 8
  %0 = load %struct.list_table** %table.addr, align 8
  %tobool = icmp ne %struct.list_table* %0, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  store i64 0, i64* %retval
  br label %return

if.end:                                           ; preds = %entry
  %1 = load %struct.list_table** %table.addr, align 8
  %2 = load i64* %lid.addr, align 8
  %call = call %struct.list_descriptor* @find_descriptor(%struct.list_table* %1, i64 %2)
  store %struct.list_descriptor* %call, %struct.list_descriptor** %desc, align 8
  %3 = load %struct.list_descriptor** %desc, align 8
  %tobool1 = icmp ne %struct.list_descriptor* %3, null
  br i1 %tobool1, label %if.end3, label %if.then2

if.then2:                                         ; preds = %if.end
  store i64 0, i64* %retval
  br label %return

if.end3:                                          ; preds = %if.end
  %4 = load %struct.list_descriptor** %desc, align 8
  %5 = load i64* %pos.addr, align 8
  %call4 = call i8* @remove_list_element(%struct.list_descriptor* %4, i64 %5)
  store i8* %call4, i8** %value, align 8
  %6 = load i8** %value, align 8
  %7 = bitcast i8* %6 to i64*
  %8 = load i64* %7, align 8
  store i64 %8, i64* %casted_value, align 8
  %9 = load i8** %value, align 8
  call void @free(i8* %9) #4
  %10 = load i64* %casted_value, align 8
  store i64 %10, i64* %retval
  br label %return

return:                                           ; preds = %if.end3, %if.then2, %if.then
  %11 = load i64* %retval
  ret i64 %11
}

; Function Attrs: nounwind uwtable
define internal %struct.node_t* @create_node(%struct.node_t* %next, %struct.node_t* %prev, i8* %value, i64 %type) #0 {
entry:
  %next.addr = alloca %struct.node_t*, align 8
  %prev.addr = alloca %struct.node_t*, align 8
  %value.addr = alloca i8*, align 8
  %type.addr = alloca i64, align 8
  %node = alloca %struct.node_t*, align 8
  store %struct.node_t* %next, %struct.node_t** %next.addr, align 8
  store %struct.node_t* %prev, %struct.node_t** %prev.addr, align 8
  store i8* %value, i8** %value.addr, align 8
  store i64 %type, i64* %type.addr, align 8
  %call = call noalias i8* @malloc(i64 24) #4
  %0 = bitcast i8* %call to %struct.node_t*
  store %struct.node_t* %0, %struct.node_t** %node, align 8
  %1 = load %struct.node_t** %node, align 8
  %tobool = icmp ne %struct.node_t* %1, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %2 = load %struct._IO_FILE** @stderr, align 8
  %call1 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %2, i8* getelementptr inbounds ([44 x i8]* @.str2, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

if.end:                                           ; preds = %entry
  %3 = load %struct.node_t** %next.addr, align 8
  %4 = load %struct.node_t** %node, align 8
  %next2 = getelementptr inbounds %struct.node_t* %4, i32 0, i32 1
  store %struct.node_t* %3, %struct.node_t** %next2, align 8
  %5 = load %struct.node_t** %prev.addr, align 8
  %6 = load %struct.node_t** %node, align 8
  %prev3 = getelementptr inbounds %struct.node_t* %6, i32 0, i32 2
  store %struct.node_t* %5, %struct.node_t** %prev3, align 8
  %7 = load i8** %value.addr, align 8
  %8 = load i64* %type.addr, align 8
  %call4 = call i8* @cpy_value(i8* %7, i64 %8)
  %9 = load %struct.node_t** %node, align 8
  %value5 = getelementptr inbounds %struct.node_t* %9, i32 0, i32 0
  store i8* %call4, i8** %value5, align 8
  %10 = load %struct.node_t** %node, align 8
  ret %struct.node_t* %10
}

; Function Attrs: nounwind uwtable
define internal i8* @cpy_value(i8* %value, i64 %type) #0 {
entry:
  %value.addr = alloca i8*, align 8
  %type.addr = alloca i64, align 8
  %cpy = alloca i8*, align 8
  store i8* %value, i8** %value.addr, align 8
  store i64 %type, i64* %type.addr, align 8
  %0 = load i64* %type.addr, align 8
  %call = call i64 @num_bytes(i64 %0)
  %call1 = call noalias i8* @malloc(i64 %call) #4
  store i8* %call1, i8** %cpy, align 8
  %1 = load i8** %cpy, align 8
  %tobool = icmp ne i8* %1, null
  br i1 %tobool, label %if.end, label %if.then

if.then:                                          ; preds = %entry
  %2 = load %struct._IO_FILE** @stderr, align 8
  %call2 = call i32 (%struct._IO_FILE*, i8*, ...)* @fprintf(%struct._IO_FILE* %2, i8* getelementptr inbounds ([42 x i8]* @.str3, i32 0, i32 0))
  call void @exit(i32 1) #5
  unreachable

if.end:                                           ; preds = %entry
  %3 = load i8** %cpy, align 8
  %4 = load i8** %value.addr, align 8
  %5 = load i64* %type.addr, align 8
  %call3 = call i64 @num_bytes(i64 %5)
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* %3, i8* %4, i64 %call3, i32 1, i1 false)
  %6 = load i8** %cpy, align 8
  ret i8* %6
}

; Function Attrs: nounwind uwtable
define internal i64 @num_bytes(i64 %type) #0 {
entry:
  %type.addr = alloca i64, align 8
  store i64 %type, i64* %type.addr, align 8
  %0 = load i64* %type.addr, align 8
  %arrayidx = getelementptr inbounds [5 x i64]* @bytes_per_type, i32 0, i64 %0
  %1 = load i64* %arrayidx, align 8
  ret i64 %1
}

; Function Attrs: nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture, i64, i32, i1) #4

; Function Attrs: nounwind uwtable
define internal void @free_node(%struct.node_t* %node) #0 {
entry:
  %node.addr = alloca %struct.node_t*, align 8
  store %struct.node_t* %node, %struct.node_t** %node.addr, align 8
  %0 = load %struct.node_t** %node.addr, align 8
  %tobool = icmp ne %struct.node_t* %0, null
  br i1 %tobool, label %if.then, label %if.end

if.then:                                          ; preds = %entry
  %1 = load %struct.node_t** %node.addr, align 8
  %value = getelementptr inbounds %struct.node_t* %1, i32 0, i32 0
  %2 = load i8** %value, align 8
  call void @free(i8* %2) #4
  br label %if.end

if.end:                                           ; preds = %if.then, %entry
  %3 = load %struct.node_t** %node.addr, align 8
  %4 = bitcast %struct.node_t* %3 to i8*
  call void @free(i8* %4) #4
  ret void
}

; Function Attrs: nounwind uwtable
define internal i64 @unique_desc_id() #0 {
entry:
  %0 = load i64* @list_counter, align 8
  %inc = add i64 %0, 1
  store i64 %inc, i64* @list_counter, align 8
  ret i64 %0
}

attributes #0 = { nounwind uwtable "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #2 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #3 = { noreturn nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf"="true" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #4 = { nounwind }
attributes #5 = { noreturn nounwind }
