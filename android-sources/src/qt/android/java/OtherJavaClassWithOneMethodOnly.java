package qt.android.java;

import qt.android.nativelibrary.SomeLibraryClass;

public class OtherJavaClassWithOneMethodOnly {
    public static String getMeSomeStringFromTheLibraryHey() {
        String str = SomeLibraryClass.someString();
        return str;
    }
}
