package org.ice1000.math

import org.ice1000.test.test
import org.junit.Assert.*
import org.junit.BeforeClass
import org.junit.Test
import java.util.*

/**
 * Created by ice1000 on 2016/11/16.

 * @author ice1000
 */
class MathUtilsTest {

	@Test(timeout = 100)
	fun basic() {
		assertEquals(4, 2L + 2L)
	}

	@Test(timeout = 100)
	fun gcd() {
		assertEquals(MathUtils.gcd(12, 15), 3)
		assertEquals(MathUtils.gcd(12, 16), 4)
		assertEquals(MathUtils.gcd(15, 20), 5)
		assertEquals(MathUtils.gcd(100, 1000), 100)
		assertEquals(MathUtils.gcd(1000, 100), 100)
		assertEquals(MathUtils.gcd(1, 1), 1)
		println("discretizationTest passed")
	}

	/**
	 * 2.5e-4ms per calc
	 */
	@Test(timeout = 500)
	fun sqrtTime() {
		val random = Random(System.currentTimeMillis())
		test(1000000) {
			@Suppress("DEPRECATION")
			MathUtils.sqrtStrict(random.nextDouble() * 10000)
		}
		println("discretizationTest passed")
	}

	/**
	 * 2.5e-4ms per calc
	 */
	@Test(timeout = 100)
	@SuppressWarnings("ResultOfMethodCallIgnored")
	fun sqrtStdTime() {
		val random = Random(System.currentTimeMillis())
		test(1000000) {
			@Suppress("DEPRECATION")
			MathUtils.sqrt(random.nextDouble() * 10000)
		}
		println("discretizationTest passed")
	}

	@Test(timeout = 100)
	@SuppressWarnings("deprecation")
	fun sqrtCorrectness() {
		val random = Random(System.currentTimeMillis())
		val testNumber = random.nextDouble() * 10000
		@Suppress("DEPRECATION")
		println(MathUtils.sqrt(testNumber))
		println(MathUtils.sqrtStrict(testNumber))
		println(Math.sqrt(testNumber))
		test(5000) {
			val temp = random.nextDouble()
			@Suppress("DEPRECATION")
			assertTrue(MathUtils.abs(MathUtils.sqrt(temp) - Math.sqrt(temp)) < 1e-5)
			assertTrue(MathUtils.abs(MathUtils.sqrtStrict(temp) - Math.sqrt(temp)) < 1e-10)
		}
	}

	/**
	 * fast power and fast plus discretizationTest
	 *
	 *
	 * data:
	 * 2 ^ 10 => 1024, 1024 % 1000 => 24
	 * 2 ^ 9 => 512, 512 % 100 => 12
	 * 2 ^ 10 => 1024, 1024 % 10 => 4
	 * 233 * 233 => 54289, 54289 % 1000 => 289
	 */
	@Test(timeout = 100)
	fun fastPlusPowerTest() {
		assertEquals(24, MathUtils.fastPower(2, 10, 1000))
		assertEquals(12, MathUtils.fastPower(2, 9, 100))
		assertEquals(4, MathUtils.fastPower(2, 10, 10))
		assertEquals(289, MathUtils.fastPlus(233, 233, 1000))
	}

	/**
	 * abstract value
	 */
	@Test(timeout = 100)
	fun absTest() {
		val random = Random(System.currentTimeMillis())
		test(4000) {
			val anInt = random.nextInt()
			val aDouble = random.nextDouble()
			val aLong = random.nextLong()
			val aFloat = random.nextFloat()
			assertEquals(MathUtils.abs(anInt).toLong(), MathUtils.abs(anInt).toLong())
			assertEquals(MathUtils.abs(aLong), MathUtils.abs(aLong))
			assertEquals(MathUtils.abs(aDouble), MathUtils.abs(aDouble), 1e-15)
			assertEquals(MathUtils.abs(aFloat).toDouble(), MathUtils.abs(aFloat).toDouble(), 1e-15)
		}
	}

	/**
	 * min max value
	 */
	@Test(timeout = 100)
	fun minMaxTest() {
		val random = Random(System.currentTimeMillis())
		test(1000) {
			val anInt = random.nextInt()
			val anInt2 = random.nextInt()
			val aDouble = random.nextDouble()
			val aDouble2 = random.nextDouble()
			val aLong = random.nextLong()
			val aLong2 = random.nextLong()
			val aFloat = random.nextFloat()
			val aFloat2 = random.nextFloat()
			assertEquals(
					MathUtils.min(anInt, anInt2).toLong(),
					Math.min(anInt, anInt2).toLong())
			assertEquals(
					MathUtils.min(aLong, aLong2),
					Math.min(aLong, aLong2))
			assertEquals(
					MathUtils.min(aDouble, aDouble2),
					Math.min(aDouble, aDouble2), 1e-15)
			assertEquals(
					MathUtils.min(aFloat, aFloat2).toDouble(),
					Math.min(aFloat, aFloat2).toDouble(), 1e-15)
			assertEquals(
					MathUtils.max(anInt, anInt2),
					Math.max(anInt, anInt2).toLong())
			assertEquals(
					MathUtils.max(aLong, aLong2),
					Math.max(aLong, aLong2))
			assertEquals(
					MathUtils.max(aDouble, aDouble2),
					Math.max(aDouble, aDouble2), 1e-15)
			assertEquals(
					MathUtils.max(aFloat, aFloat2).toDouble(),
					Math.max(aFloat, aFloat2).toDouble(), 1e-15)
		}
	}

	@Test(timeout = 50)
	fun logTest() {
		val random = Random(System.currentTimeMillis())
		test(5000) {
			val temp = random.nextDouble()
			assertEquals(
					MathUtils.ln(temp),
					Math.log(temp), 1e-15)
			assertEquals(
					MathUtils.lg(temp),
					Math.log10(temp), 1e-15)
		}
	}

	@Test(timeout = 1000)
	fun isPrimeTest() {
		val primes = listOf(
				2L, 3L, 5L, 7L,
				11L, 13L, 17L, 19L,
				23L, 29L, 31L, 37L,
				41L, 43L, 47L, 53L,
				59L, 61L, 67L, 71L,
				73L, 79L, 83L, 89L,
				97L, 101L)
		(0L..102L).forEach { i ->
			if (primes.contains(i)) assertTrue(MathUtils.isPrime(i))
			else assertFalse(MathUtils.isPrime(i))
		}
		val rand = Random(System.currentTimeMillis())
		test(1000) {
			assertFalse(MathUtils.isPrime(
					((MathUtils.abs(rand.nextInt(100)) + 2) *
							(MathUtils.abs(rand.nextInt(100)) + 2)).toLong()
			))
		}
	}

	companion object Initializer {

		@BeforeClass
		@JvmStatic
		fun loadJniLibrary() {
			System.loadLibrary("jni")
		}
	}
}
