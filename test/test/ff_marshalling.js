const { expect } = require('chai');
const dut = require('../dut');
const {
  assertErrorMsg,
  getTypeErrMsg,
  values
} = require('./utils');

const {
  aBool, aNumber, anInt, anUint, aString
} = values;

const aBoolArray = Array(5).fill(aBool);
const aNumberArray = Array(5).fill(aNumber);
const anIntArray = Array(5).fill(anInt);
const anUintArray = Array(5).fill(anUint);
const aStringArray = Array(5).fill(aString);

describe('ff_marshalling - packing and unpacking', () => {
  describe('unpack array', () => {
    describe('unpack bool array', () => {
      it('should NOT throw', () => {
        expect(() => dut.unpackBoolArray(aBoolArray)).not.to.throw();
      });

      it('should throw type error', () => {
        [aNumber, anInt, anUint, aString].forEach(
          val => assertErrorMsg(
            () => dut.unpackBoolArray(aBoolArray.concat(val)),
            getTypeErrMsg('BOOL')
          )
        );
      });
    });

    describe('unpack number array', () => {
      it('should NOT throw', () => {
        expect(() => dut.unpackNumberArray(aNumberArray)).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aString].forEach(
          val => assertErrorMsg(
            () => dut.unpackNumberArray(aNumberArray.concat(val)),
            getTypeErrMsg('NUMBER')
          )
        );
      });
    });

    describe('unpack int array', () => {
      it('should NOT throw', () => {
        expect(() => dut.unpackIntArray(anIntArray)).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aNumber, aString].forEach(
          val => assertErrorMsg(
            () => dut.unpackIntArray(anIntArray.concat(val)),
            getTypeErrMsg('INT')
          )
        );
      });
    });

    describe('unpack uint array', () => {
      it('should NOT throw', () => {
        expect(() => dut.unpackUintArray(anUintArray)).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aNumber, aString].forEach(
          val => assertErrorMsg(
            () => dut.unpackUintArray(anUintArray.concat(val)),
            getTypeErrMsg('UINT')
          )
        );
      });
    });

    describe('unpack string array', () => {
      it('should NOT throw', () => {
        expect(() => dut.unpackStringArray(aStringArray)).not.to.throw();
      });

      it('should throw type error', () => {
        [aBool, aNumber, anInt, anUint].forEach(
          val => assertErrorMsg(
            () => dut.unpackStringArray(aStringArray.concat(val)),
            getTypeErrMsg('STRING')
          )
        );
      });
    });

    describe('unpack and pack bool array', () => {
      it('should return input array', () => {
        const arr = dut.unpackAndPackBoolArray(aBoolArray);
        expect(arr).to.be.an('array').lengthOf(aBoolArray.length);
        expect(arr).to.have.members(aBoolArray);
      });
    });

    describe('unpack and pack number array', () => {
      it('should return input array', () => {
        const arr = dut.unpackAndPackNumberArray(aNumberArray);
        expect(arr).to.be.an('array').lengthOf(aNumberArray.length);
        expect(arr).to.have.members(aNumberArray);
      });
    });

    describe('unpack and pack int array', () => {
      it('should return input array', () => {
        const arr = dut.unpackAndPackIntArray(anIntArray);
        expect(arr).to.be.an('array').lengthOf(anIntArray.length);
        expect(arr).to.have.members(anIntArray);
      });
    });

    describe('unpack and pack uint array', () => {
      it('should return input array', () => {
        const arr = dut.unpackAndPackUintArray(anUintArray);
        expect(arr).to.be.an('array').lengthOf(anUintArray.length);
        expect(arr).to.have.members(anUintArray);
      });
    });

    describe('unpack and pack string array', () => {
      it('should return input array', () => {
        const arr = dut.unpackAndPackStringArray(aStringArray);
        expect(arr).to.be.an('array').lengthOf(aStringArray.length);
        expect(arr).to.have.members(aStringArray);
      });
    });
  });
});
