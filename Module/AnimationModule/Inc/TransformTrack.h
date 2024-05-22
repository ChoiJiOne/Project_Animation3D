#pragma once

#include "Transform.h"

#include "Track.h"


/**
 * @brief 고수준 변형 트랙(Transform Track)입니다.
 * 
 * @note 이 변형 트랙은 세 가지 트랙(위치, 회전, 스케일)을 캡슐화합니다.
 */
class TransformTrack
{
public:
	/**
	 * @brief 고수준 변형 트랙(Transform Track)의 기본 생성자입니다
	 */
	TransformTrack() = default;


	/**
	 * @brief 고수준 변형 트랙(Transform Track)의 복사 생성자입니다.
	 * 
	 * @param instance 복사할 인스턴스입니다.
	 */
	TransformTrack(TransformTrack&& instance) noexcept
		: boneID_(instance.boneID_)
		, position_(instance.position_)
		, rotate_(instance.rotate_)
		, scale_(instance.scale_) 
	{
		position_ = instance.position_;

	}


	/**
	 * @brief 고수준 변형 트랙(Transform Track)의 복사 생성자입니다.
	 *
	 * @param instance 복사할 인스턴스입니다.
	 */
	TransformTrack(const TransformTrack& instance) noexcept
		: boneID_(instance.boneID_)
		, position_(instance.position_)
		, rotate_(instance.rotate_)
		, scale_(instance.scale_) {}


	/**
	 * @brief 고수준 변형 트랙(Transform Track)의 가상 소멸자입니다
	 */
	virtual ~TransformTrack() {}


	/**
	 * @brief 고수준 변형 트랙의 대입 연산자입니다.
	 *
	 * @param instance 대입 연산을 수행할 인스턴스입니다.
	 *
	 * @return 대입 연산을 수행한 객체의 참조자를 반환합니다.
	 */
	TransformTrack& operator=(TransformTrack&& instance) noexcept
	{
		if (this == &instance) return *this;

		boneID_ = instance.boneID_;
		position_ = instance.position_;
		rotate_ = instance.rotate_;
		scale_ = instance.scale_;

		return *this;
	}


	/**
	 * @brief 고수준 변형 트랙의 대입 연산자입니다.
	 *
	 * @param instance 대입 연산을 수행할 인스턴스입니다.
	 *
	 * @return 대입 연산을 수행한 객체의 참조자를 반환합니다.
	 */
	TransformTrack& operator=(const TransformTrack& instance) noexcept
	{
		if (this == &instance) return *this;

		boneID_ = instance.boneID_;
		position_ = instance.position_;
		rotate_ = instance.rotate_;
		scale_ = instance.scale_;

		return *this;
	}


	/**
	 * @brief 뼈대 ID를 얻습니다.
	 * 
	 * @return 뼈대 ID를 반환합니다.
	 */
	uint32_t GetBoneID() const { return boneID_; }


	/**
	 * @brief 뼈대 ID를 설정합니다.
	 * 
	 * @param boneID 설정할 뼈대 ID입니다.
	 */
	void SetBoneID(uint32_t boneID) { boneID_ = boneID; }


	/**
	 * @brief 위치 트랙의 참조자를 얻습니다.
	 * 
	 * @return 위치 트랙의 참조자를 반환합니다.
	 */
	VectorTrack& GetPositionTrack() { return position_; }


	/**
	 * @brief 위치 트랙의 상수 참조자를 얻습니다.
	 *
	 * @return 위치 트랙의 상수 참조자를 반환합니다.
	 */
	const VectorTrack& GetPositionTrack() const { return position_; }
	

private:
	/**
	 * @brief 뼈대 ID입니다.
	 */
	uint32_t boneID_ = 0;


	/**
	 * @brief 위치 트랙입니다.
	 */
	VectorTrack position_;


	/**
	 * @brief 회전 트랙입니다.
	 */
	QuaternionTrack rotate_;


	/**
	 * @brief 스케일 트랙입니다.
	 */
	VectorTrack scale_;
};