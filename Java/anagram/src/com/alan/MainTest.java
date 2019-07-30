package com.alan;

import org.junit.Assert;
import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import static com.alan.Main.reverse;
import static org.junit.jupiter.api.Assertions.*;

class MainTest {

    @Test
    void reverseTest() {
        Assert.assertEquals("ahah", reverse("haha"));
    }

    @Test
    void testReverseSpecial() {
        Assert.assertEquals("$^*G$F%^H", reverse("H^%F$G*^$"));
    }

}
