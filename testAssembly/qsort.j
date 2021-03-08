.class public qsort
.super java/lang/Object
.field public static i I
.field public static j I
.field public static tmp I
.field public static size I
.field public static arr [I
.method public static readArr([I)V
.limit locals 50
.limit stack 50
    ldc 0
    istore 1
    ldc 0
    putstatic qsort/size I
    invokestatic io/readlnI()I
    istore 1
L1:
    iload  1
    ldc 0
    if_icmpne L2
    ldc 0
    goto L3
L2:
    ldc 1
L3:
    ifeq L4
    getstatic qsort/size I
    ldc 1
    iadd
    putstatic qsort/size I
    getstatic qsort/arr [I
    getstatic qsort/size I
    ldc 1
    isub
    iload  1
    iastore
    invokestatic io/readlnI()I
    istore 1
    goto L1
L4:
    return
.end method
.method public static split(II)I
.limit locals 50
.limit stack 50
    ldc 0
    istore 2
    ldc 0
    istore 3
    ldc 0
    istore 4
    ldc 0
    istore 5
    ldc 0
    istore 6
    getstatic qsort/arr [I
    iload  0
    ldc 1
    isub
    iaload
    istore 5
    iload  0
    ldc 1
    iadd
    istore 3
    iload  1
    istore 4
L5:
    iload  3
    iload  4
    if_icmple L6
    ldc 0
    goto L7
L6:
    ldc 1
L7:
    ifeq L8
    ldc 1
    istore 2
    iload  3
    iload  1
    if_icmple L9
    ldc 0
    goto L10
L9:
    ldc 1
L10:
    ifne L11
    ldc 0
    istore 2
    goto L12
L11:
    goto L12
L12:
    iload  2
    ldc 1
    if_icmpeq L13
    ldc 0
    goto L14
L13:
    ldc 1
L14:
    ifne L15
    goto L16
L15:
    getstatic qsort/arr [I
    iload  3
    ldc 1
    isub
    iaload
    iload  5
    if_icmplt L17
    ldc 0
    goto L18
L17:
    ldc 1
L18:
    ifne L19
    ldc 0
    istore 2
    goto L20
L19:
    goto L20
L20:
    goto L16
L16:
L21:
    iload  2
    ldc 1
    if_icmpeq L22
    ldc 0
    goto L23
L22:
    ldc 1
L23:
    ifeq L24
    iload  3
    ldc 1
    iadd
    istore 3
    ldc 1
    istore 2
    iload  3
    iload  1
    if_icmple L25
    ldc 0
    goto L26
L25:
    ldc 1
L26:
    ifne L27
    ldc 0
    istore 2
    goto L28
L27:
    goto L28
L28:
    iload  2
    ldc 1
    if_icmpeq L29
    ldc 0
    goto L30
L29:
    ldc 1
L30:
    ifne L31
    goto L32
L31:
    getstatic qsort/arr [I
    iload  3
    ldc 1
    isub
    iaload
    iload  5
    if_icmplt L33
    ldc 0
    goto L34
L33:
    ldc 1
L34:
    ifne L35
    ldc 0
    istore 2
    goto L36
L35:
    goto L36
L36:
    goto L32
L32:
    goto L21
L24:
    ldc 1
    istore 2
    iload  4
    iload  0
    if_icmpgt L37
    ldc 0
    goto L38
L37:
    ldc 1
L38:
    ifne L39
    ldc 0
    istore 2
    goto L40
L39:
    goto L40
L40:
    iload  2
    ldc 1
    if_icmpeq L41
    ldc 0
    goto L42
L41:
    ldc 1
L42:
    ifne L43
    goto L44
L43:
    getstatic qsort/arr [I
    iload  4
    ldc 1
    isub
    iaload
    iload  5
    if_icmpge L45
    ldc 0
    goto L46
L45:
    ldc 1
L46:
    ifne L47
    ldc 0
    istore 2
    goto L48
L47:
    goto L48
L48:
    goto L44
L44:
L49:
    iload  2
    ldc 1
    if_icmpeq L50
    ldc 0
    goto L51
L50:
    ldc 1
L51:
    ifeq L52
    iload  4
    ldc 1
    isub
    istore 4
    ldc 1
    istore 2
    iload  4
    iload  0
    if_icmpgt L53
    ldc 0
    goto L54
L53:
    ldc 1
L54:
    ifne L55
    ldc 0
    istore 2
    goto L56
L55:
    goto L56
L56:
    iload  2
    ldc 1
    if_icmpeq L57
    ldc 0
    goto L58
L57:
    ldc 1
L58:
    ifne L59
    goto L60
L59:
    getstatic qsort/arr [I
    iload  4
    ldc 1
    isub
    iaload
    iload  5
    if_icmpge L61
    ldc 0
    goto L62
L61:
    ldc 1
L62:
    ifne L63
    ldc 0
    istore 2
    goto L64
L63:
    goto L64
L64:
    goto L60
L60:
    goto L49
L52:
    iload  3
    iload  4
    if_icmplt L65
    ldc 0
    goto L66
L65:
    ldc 1
L66:
    ifne L67
    goto L68
L67:
    getstatic qsort/arr [I
    iload  3
    ldc 1
    isub
    iaload
    istore 6
    getstatic qsort/arr [I
    iload  3
    ldc 1
    isub
    getstatic qsort/arr [I
    iload  4
    ldc 1
    isub
    iaload
    iastore
    getstatic qsort/arr [I
    iload  4
    ldc 1
    isub
    iload  6
    iastore
    goto L68
L68:
    goto L5
L8:
    getstatic qsort/arr [I
    iload  0
    ldc 1
    isub
    iaload
    istore 6
    getstatic qsort/arr [I
    iload  0
    ldc 1
    isub
    getstatic qsort/arr [I
    iload  4
    ldc 1
    isub
    iaload
    iastore
    getstatic qsort/arr [I
    iload  4
    ldc 1
    isub
    iload  6
    iastore
    iload  4
    ireturn
.end method
.method public static quicksortRecur(II)V
.limit locals 50
.limit stack 50
    ldc 0
    istore 2
    ldc 0
    istore 3
    iload  0
    iload  1
    if_icmplt L69
    ldc 0
    goto L70
L69:
    ldc 1
L70:
    ifne L71
    goto L72
L71:
    iload  0
    iload  1
    invokestatic qsort/split(II)I
    istore 3
    iload  0
    iload  3
    ldc 1
    isub
    invokestatic qsort/quicksortRecur(II)V
    iload  3
    ldc 1
    iadd
    iload  1
    invokestatic qsort/quicksortRecur(II)V
    goto L72
L72:
    return
.end method
.method public static quicksort([I)V
.limit locals 50
.limit stack 50
    ldc 1
    getstatic qsort/size I
    invokestatic qsort/quicksortRecur(II)V
    return
.end method
.method public static main([Ljava/lang/String;)V
.limit locals 50
.limit stack 50
    ldc 0
    putstatic qsort/i I
    ldc 0
    putstatic qsort/j I
    ldc 0
    putstatic qsort/tmp I
    ldc 0
    putstatic qsort/size I
    ldc 50
    multianewarray [I 1
    putstatic qsort/arr [I
    getstatic qsort/arr [I
    invokestatic qsort/readArr([I)V
    getstatic qsort/arr [I
    invokestatic qsort/quicksort([I)V
    ldc 1
    putstatic qsort/i I
L73:
    getstatic qsort/i I
    getstatic qsort/size I
    if_icmple L74
    ldc 0
    goto L75
L74:
    ldc 1
L75:
    ifeq L76
    getstatic qsort/arr [I
    getstatic qsort/i I
    ldc 1
    isub
    iaload
    invokestatic io/writelnI(I)V
    getstatic qsort/i I
    ldc 1
    iadd
    putstatic qsort/i I
    goto L73
L76:
    return
.end method
