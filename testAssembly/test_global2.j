.class public test_global2
.super java/lang/Object
.field public static a I
.field public static b I
.field public static c F
.method public static tt()I
.limit locals 50
.limit stack 50
    ldc 3
    istore_0
    iload_0
    ldc 5
    iadd
    istore_1
    iload_1
    ireturn

.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic test_global2/a I
    ldc 0
    putstatic test_global2/b I
    ldc 0.0
    putstatic test_global2/c F
    
    ldc 3
    putstatic test_global2/a I
    ldc 4
    putstatic test_global2/b I

    invokestatic test_global2/tt()I
    invokestatic io/writelnI(I)V

    return
.end method

