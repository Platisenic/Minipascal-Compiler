.class public test_procedure
.super java/lang/Object
.field public static a I
.field public static b I
.field public static c F
.method public static ss()I
.limit locals 50
.limit stack 50
    ldc 4
    ldc 5
    imul
    ldc 3
    iadd
    ireturn
.end method
.method public static tt()V
.limit locals 50
.limit stack 50
    ldc 33
    invokestatic test_procedure/ss()I
    imul
    invokestatic test_procedure/ss()I
    iadd
    getstatic test_procedure/a I
    iadd
    putstatic test_procedure/a I
    
    ldc 0.5
    putstatic test_procedure/c F
    return

.end method



.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic test_procedure/a I
    ldc 0
    putstatic test_procedure/b I
    ldc 0.0
    putstatic test_procedure/c F
    
    invokestatic test_procedure/ss()I
    invokestatic test_procedure/ss()I
    imul
    invokestatic test_procedure/ss()I
    iadd
    
    putstatic test_procedure/a I


    invokestatic test_procedure/tt()V
    invokestatic test_procedure/tt()V
    invokestatic test_procedure/tt()V

    getstatic test_procedure/a I
    invokestatic io/writelnI(I)V

    return
.end method

