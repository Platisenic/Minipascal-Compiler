.class public test_con_prop
.super java/lang/Object
.field public static a [I
.field public static b I
.field public static c [[I
.method public static ss(I)I
.limit locals 50
.limit stack 50
    iload  0
    ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 2
    multianewarray [I 1
    putstatic test_con_prop/a [I
    ldc 0
    putstatic test_con_prop/b I
    ldc 2
    ldc 2
    multianewarray [[I 2
    putstatic test_con_prop/c [[I
    getstatic test_con_prop/a [I
    ldc 3
    ldc 4
    iadd
    ldc 6
    isub
    ldc 1
    isub
    ldc 10
    iastore
    getstatic test_con_prop/c [[I
    ldc 1
    ldc 100
    ldc 0
    imul
    iadd
    ldc 1
    iadd
    ldc 1
    isub
    aaload
    ldc 2
    ldc 4
    ldc 2
    idiv
    iadd
    ldc 3
    isub
    ldc 100
    iastore
    getstatic test_con_prop/a [I
    ldc 1
    ldc 1
    isub
    iaload
    invokestatic io/writelnI(I)V
    getstatic test_con_prop/c [[I
    ldc 2
    ldc 1
    isub
    aaload
    ldc 4
    ldc 3
    isub
    iaload
    invokestatic io/writelnI(I)V
    return
.end method
