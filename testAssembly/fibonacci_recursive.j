.class public fibonacci_recursive
.super java/lang/Object
.field public static a I
.method public static fa(I)I
.limit locals 50
.limit stack 50
    iload_0
    ldc 1
    if_icmpeq L1
    ldc 0
    goto L2
L1:
    ldc 1
L2:
    ifne L3
    iload_0
    ldc 0
    if_icmpeq L4
    ldc 0
    goto L5
L4:
    ldc 1
L5:
    ifne L6
    iload_0
    ldc 1
    isub
    invokestatic fibonacci_recursive/fa(I)I
    iload_0
    ldc 2
    isub
    invokestatic fibonacci_recursive/fa(I)I
    iadd
    goto L8
L6:
    ldc 0
    goto L8
L7:
    goto L4
L3:
    ldc 1
L8:
    ireturn
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic fibonacci_recursive/a I
    ldc 10
    putstatic fibonacci_recursive/a I
    getstatic fibonacci_recursive/a I
    invokestatic fibonacci_recursive/fa(I)I
    invokestatic io/writelnI(I)V
    return
.end method

