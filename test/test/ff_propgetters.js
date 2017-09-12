const { expect } = require('chai');
const dut = require('../dut');
const {
  assertErrorMsg,
  getTypeErrMsg,
  getPropRequiredErrMsg,
  getPropTypeErrMsg,
  values
} = require('./utils');

const {
  aBool, aNumber, anInt, anUint, aString, anArray, anObject,
  aBoolDefault, aNumberDefault, anIntDefault, anUintDefault, aStringDefault
} = values;

const generateArrayPropTests = ({ type, throwForTypes, validValues }) => {
  describe(`${type} array`, () => {
    const method = `getUnpackAndReturn${`${type[0].toUpperCase()}${type.substr(1)}`}Array`;
    const propName = `${type}Array`;
    it('should throw prop required', () => {
      assertErrorMsg(() => dut[method]({}), getPropRequiredErrMsg(method, propName));
    });

    it('should throw type error, expected array', () => {
      assertErrorMsg(() => dut[method]({ [propName]: undefined }), getPropTypeErrMsg(method, propName, 'ARRAY'));
    });

    it('should NOT throw if array is empty', () => {
      expect(() => dut[method]({ [propName]: [] })).not.to.throw();
    });

    it('should NOT throw if array of valid types', () => {
      validValues.forEach((val) => {
        expect(() => dut[method]({ [propName]: [val] })).not.to.throw();
      });
    });

    it('should throw type error if array contains invalid values', () => {
      throwForTypes.forEach((val) => {
        assertErrorMsg(
          () => dut[method]({ [propName]: [validValues[0], val] }),
          getTypeErrMsg(type.toUpperCase())
        );
      });
    });

    it('should return prop value', () => {
      const ret = dut[method]({ [propName]: [validValues[0]] });
      expect(ret).to.be.an('array');
      expect(ret).to.have.members([validValues[0]]);
    });
  });
};

const generateOptArrayPropTests = ({ type, throwForTypes, validValues, defaultVal, assertDefaultVal }) => {
  describe(`${type} array`, () => {
    const method = `getUnpackAndReturnOpt${`${type[0].toUpperCase()}${type.substr(1)}`}Array`;
    const propName = `${type}Array`;
    it('should NOT throw if not has property', () => {
      expect(() => dut[method]({})).not.to.throw();
    });

    it('should throw type error, expected array if has prop', () => {
      assertErrorMsg(() => dut[method]({ [propName]: undefined }), getPropTypeErrMsg(method, propName, 'ARRAY'));
    });

    it('should NOT throw if array is empty', () => {
      expect(() => dut[method]({ [propName]: [] })).not.to.throw();
    });

    it('should NOT throw if array of valid types', () => {
      validValues.forEach((val) => {
        expect(() => dut[method]({ [propName]: [val] })).not.to.throw();
      });
    });

    it('should throw type error if array contains invalid values', () => {
      throwForTypes.forEach((val) => {
        assertErrorMsg(
          () => dut[method]({ [propName]: [validValues[0], val] }),
          getTypeErrMsg(type.toUpperCase())
        );
      });
    });

    it('should return prop value if has property', () => {
      const ret = dut[method]({ [propName]: [validValues[0]] });
      expect(ret).to.be.an('array');
      expect(ret).to.have.members([validValues[0]]);
    });

    it('should return default value if not has property', () => {
      let assertType = (type === 'int' || type === 'uint') ? 'number' : type;
      assertType = assertType === 'bool' ? 'boolean' : assertType;
      const returnedDefaultVal = dut[method]({});
      expect(returnedDefaultVal).to.be.an('array').lengthOf(1);
      returnedDefaultVal.forEach((val) => {
        expect(val).to.be.a(assertType);
      });
    });
  });
};

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

  describe('array props', () => {
    generateArrayPropTests({
      type: 'bool',
      throwForTypes: [aNumber, anInt, anUint, aString, anObject, anArray],
      validValues: [aBool]
    });

    generateArrayPropTests({
      type: 'number',
      throwForTypes: [aBool, aString, anObject, anArray],
      validValues: [aNumber, anInt, anUint]
    });

    generateArrayPropTests({
      type: 'int',
      throwForTypes: [aBool, aNumber, aString, anObject, anArray],
      validValues: [anInt, anUint]
    });

    generateArrayPropTests({
      type: 'uint',
      throwForTypes: [aBool, aNumber, anInt, aString, anObject, anArray],
      validValues: [anUint]
    });

    generateArrayPropTests({
      type: 'string',
      throwForTypes: [aBool, aNumber, anInt, anUint, anObject, anArray],
      validValues: [aString]
    });

    generateArrayPropTests({
      type: 'array',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anObject],
      validValues: [anArray]
    });

    generateArrayPropTests({
      type: 'object',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anArray],
      validValues: [anObject]
    });
  });

  describe('optional array props', () => {
    generateOptArrayPropTests({
      type: 'bool',
      throwForTypes: [aNumber, anInt, anUint, aString, anObject, anArray],
      validValues: [aBool],
      defaultVal: aBoolDefault
    });

    generateOptArrayPropTests({
      type: 'number',
      throwForTypes: [aBool, aString, anObject, anArray],
      validValues: [aNumber, anInt, anUint],
      defaultVal: aNumberDefault
    });

    generateOptArrayPropTests({
      type: 'int',
      throwForTypes: [aBool, aNumber, aString, anObject, anArray],
      validValues: [anInt, anUint],
      defaultVal: anIntDefault
    });

    generateOptArrayPropTests({
      type: 'uint',
      throwForTypes: [aBool, aNumber, anInt, aString, anObject, anArray],
      validValues: [anUint],
      defaultVal: anUintDefault
    });

    generateOptArrayPropTests({
      type: 'string',
      throwForTypes: [aBool, aNumber, anInt, anUint, anObject, anArray],
      validValues: [aString],
      defaultVal: aStringDefault
    });

    generateOptArrayPropTests({
      type: 'array',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anObject],
      validValues: [anArray],
      defaultVal: []
    });

    generateOptArrayPropTests({
      type: 'object',
      throwForTypes: [aBool, aNumber, anInt, anUint, aString, anArray],
      validValues: [anObject],
      defaultVal: {}
    });
  });
});
