package com.lazystring;

import static com.lazystring.Compress.compress;
import static com.lazystring.OneAway.isOneAway;
import static com.lazystring.Unique.isUnique;
import static com.lazystring.URLify.urlify;

import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertFalse;
import static org.junit.Assert.assertTrue;

import org.junit.Test;

public class CombinedTest {
  @Test
  public void testIsUnique() {
    assertTrue(isUnique("a"));
    assertTrue(isUnique("ab"));
    assertTrue(isUnique("abcdefghijk"));

    assertFalse(isUnique("aa"));
    assertFalse(isUnique("aabababa"));
    assertFalse(isUnique("abcdefdghijk"));
  }

  @Test
  public void testCompress() {
    assertEquals("a2b2", compress("aabb"));
    assertEquals("a3e2f1", compress("aaaeef"));
    assertEquals("a4b5c2d1e6f2g3", compress("aaaabbbbbccdeeeeeeffggg"));

    assertEquals(compress("a"), "a");
    assertEquals(compress("ab"), "ab");
    assertEquals(compress("abcde"), "abcde");
  }

  @Test
  public void testIsOneAway() {
    assertTrue(isOneAway("oding", "coding"));
    assertTrue(isOneAway("captai", "captain"));
    assertTrue(isOneAway("coding", "coping"));

    assertFalse(isOneAway("ingcod", "coding"));
    assertFalse(isOneAway("hello", "hello world"));
    assertFalse(isOneAway("halo", "hello"));
  }

  @Test
  public void testUrlify() {
    char[][] testUrls = {
      "youtube.com/?q=I woke up like this        ".toCharArray(),
      "youtube.com/?q=Mask off challenge    ".toCharArray(),
      "Not really a URL?      ".toCharArray(),
    };

    for (char[] testUrl : testUrls) {
      urlify(testUrl, new String(testUrl).trim().length());
    }

    assertEquals(
      "youtube.com/?q=I%20woke%20up%20like%20this", new String(testUrls[0]));
    assertEquals(
      "youtube.com/?q=Mask%20off%20challenge", new String(testUrls[1]));
    assertEquals("Not%20really%20a%20URL?", new String(testUrls[2]));
  }
}