const { expect } = require('chai');
const dut = require('../dut');
const {
  assertErrorMsg,
  getPropRequiredErrMsg,
  getPropTypeErrMsg,
  values
} = require('./utils');

const {
  aBool, aNumber, anInt, anUint, aString, anArray, anObject,
  aBoolDefault, aNumberDefault, anIntDefault, anUintDefault, aStringDefault
} = values;

describe('ff_propgetters', () => {
  describe('required props', () => {
    describe('bool prop', () => {
      const method = 'getAndReturnABoolRequired';
      it('should throw prop required', () => {
        assertErrorMsg(() => dut[method]({}), getPropRequiredErrMsg(method, 'aBool'));
      });

      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ aBool: undefined }), getPropTypeErrMsg(method, 'aBool', 'BOOL'));
      });

      it('should NOT throw', () => {
        expect(() => dut[method]({ aBool })).not.to.throw();
      });

      it('should return prop value', () => {
        expect(dut[method]({ aBool })).to.equal(aBool);
      });
    });

    describe('number prop', () => {
      const method = 'getAndReturnANumberRequired';
      it('should throw prop required', () => {
        assertErrorMsg(() => dut[method]({}), getPropRequiredErrMsg(method, 'aNumber'));
      });

      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ aNumber: undefined }), getPropTypeErrMsg(method, 'aNumber', 'NUMBER'));
      });

      it('should NOT throw', () => {
        expect(() => dut[method]({ aNumber })).not.to.throw();
      });

      it('should return prop value', () => {
        expect(dut[method]({ aNumber })).to.equal(aNumber);
      });
    });

    describe('int prop', () => {
      const method = 'getAndReturnAnIntRequired';
      it('should throw prop required', () => {
        assertErrorMsg(() => dut[method]({}), getPropRequiredErrMsg(method, 'anInt'));
      });

      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ anInt: undefined }), getPropTypeErrMsg(method, 'anInt', 'INT'));
      });

      it('should NOT throw', () => {
        expect(() => dut[method]({ anInt })).not.to.throw();
      });

      it('should return prop value', () => {
        expect(dut[method]({ anInt })).to.equal(anInt);
      });
    });

    describe('uint prop', () => {
      const method = 'getAndReturnAnUintRequired';
      it('should throw prop required', () => {
        assertErrorMsg(() => dut[method]({}), getPropRequiredErrMsg(method, 'anUint'));
      });

      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ anUint: undefined }), getPropTypeErrMsg(method, 'anUint', 'UINT'));
      });

      it('should NOT throw', () => {
        expect(() => dut[method]({ anUint })).not.to.throw();
      });

      it('should return prop value', () => {
        expect(dut[method]({ anUint })).to.equal(anUint);
      });
    });

    describe('string prop', () => {
      const method = 'getAndReturnAStringRequired';
      it('should throw prop required', () => {
        assertErrorMsg(() => dut[method]({}), getPropRequiredErrMsg(method, 'aString'));
      });

      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ aString: undefined }), getPropTypeErrMsg(method, 'aString', 'STRING'));
      });

      it('should NOT throw', () => {
        expect(() => dut[method]({ aString })).not.to.throw();
      });

      it('should return prop value', () => {
        expect(dut[method]({ aString })).to.equal(aString);
      });
    });

    describe('array prop', () => {
      const method = 'getAndReturnAnArrayRequired';
      it('should throw prop required', () => {
        assertErrorMsg(() => dut[method]({}), getPropRequiredErrMsg(method, 'anArray'));
      });

      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ anArray: undefined }), getPropTypeErrMsg(method, 'anArray', 'ARRAY'));
      });

      it('should NOT throw', () => {
        expect(() => dut[method]({ anArray })).not.to.throw();
      });

      it('should return prop value', () => {
        expect(dut[method]({ anArray })).to.equal(anArray);
      });
    });

    describe('object prop', () => {
      const method = 'getAndReturnAnObjectRequired';
      it('should throw prop required', () => {
        assertErrorMsg(() => dut[method]({}), getPropRequiredErrMsg(method, 'anObject'));
      });

      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ anObject: undefined }), getPropTypeErrMsg(method, 'anObject', 'OBJECT'));
      });

      it('should NOT throw', () => {
        expect(() => dut[method]({ anObject })).not.to.throw();
      });

      it('should return prop value', () => {
        expect(dut[method]({ anObject })).to.equal(anObject);
      });
    });
  });

  describe('optional props', () => {
    describe('bool prop', () => {
      const method = 'getAndReturnABoolOptional';
      it('should throw type error if has property', () => {
        assertErrorMsg(() => dut[method]({ aBool: undefined }), getPropTypeErrMsg(method, 'aBool', 'BOOL'));
      });

      it('should NOT throw if not has property', () => {
        expect(() => dut[method]({})).not.to.throw();
      });

      it('should return prop value if has property', () => {
        expect(dut[method]({ aBool })).to.equal(aBool);
      });

      it('should return default value if not has property', () => {
        expect(dut[method]({})).to.equal(aBoolDefault);
      });
    });

    describe('number prop', () => {
      const method = 'getAndReturnANumberOptional';
      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ aNumber: undefined }), getPropTypeErrMsg(method, 'aNumber', 'NUMBER'));
      });

      it('should NOT throw if not has property', () => {
        expect(() => dut[method]({})).not.to.throw();
      });

      it('should return prop value if has property', () => {
        expect(dut[method]({ aNumber })).to.equal(aNumber);
      });

      it('should return default value if not has property', () => {
        expect(dut[method]({})).to.equal(aNumberDefault);
      });
    });

    describe('int prop', () => {
      const method = 'getAndReturnAnIntOptional';
      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ anInt: undefined }), getPropTypeErrMsg(method, 'anInt', 'INT'));
      });

      it('should NOT throw if not has property', () => {
        expect(() => dut[method]({})).not.to.throw();
      });

      it('should return prop value if has property', () => {
        expect(dut[method]({ anInt })).to.equal(anInt);
      });

      it('should return default value if not has property', () => {
        expect(dut[method]({})).to.equal(anIntDefault);
      });
    });

    describe('uint prop', () => {
      const method = 'getAndReturnAnUintOptional';
      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ anUint: undefined }), getPropTypeErrMsg(method, 'anUint', 'UINT'));
      });

      it('should NOT throw if not has property', () => {
        expect(() => dut[method]({})).not.to.throw();
      });

      it('should return prop value if has property', () => {
        expect(dut[method]({ anUint })).to.equal(anUint);
      });

      it('should return default value if not has property', () => {
        expect(dut[method]({})).to.equal(anUintDefault);
      });
    });

    describe('string prop', () => {
      const method = 'getAndReturnAStringOptional';
      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ aString: undefined }), getPropTypeErrMsg(method, 'aString', 'STRING'));
      });

      it('should NOT throw if not has property', () => {
        expect(() => dut[method]({})).not.to.throw();
      });

      it('should return prop value if has property', () => {
        expect(dut[method]({ aString })).to.equal(aString);
      });

      it('should return default value if not has property', () => {
        expect(dut[method]({})).to.equal(aStringDefault);
      });
    });

    describe('array prop', () => {
      const method = 'getAndReturnAnArrayOptional';
      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ anArray: undefined }), getPropTypeErrMsg(method, 'anArray', 'ARRAY'));
      });

      it('should NOT throw if not has property', () => {
        expect(() => dut[method]({})).not.to.throw();
      });

      it('should return prop value if has property', () => {
        expect(dut[method]({ anArray })).to.equal(anArray);
      });

      it('should return default value if not has property', () => {
        const defaultArr = dut[method]({});
        expect(defaultArr).to.be.an('array').lengthOf(1);
        expect(defaultArr[0]).to.equal(true);
      });
    });

    describe('object prop', () => {
      const method = 'getAndReturnAnObjectOptional';
      it('should throw type error', () => {
        assertErrorMsg(() => dut[method]({ anObject: undefined }), getPropTypeErrMsg(method, 'anObject', 'OBJECT'));
      });

      it('should NOT throw if not has property', () => {
        expect(() => dut[method]({})).not.to.throw();
      });

      it('should return prop value if has property', () => {
        expect(dut[method]({ anObject })).to.equal(anObject);
      });

      it('should return default value if not has property', () => {
        const defaultObj = dut[method]({});
        expect(defaultObj).to.have.property('default').to.equal(true);
      });
    });
  });
});
