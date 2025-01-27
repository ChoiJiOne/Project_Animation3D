#pragma once

#include <imgui.h>

#include "CrossFadeController.h"
#include "IEntity.h"
#include "ITexture2D.h"
#include "Skeleton.h"
#include "SkinnedMesh.h"

class Camera;


/**
 * @brief 캐릭터 엔티티입니다.
 */
class Character : public IEntity
{
public:
	/**
	 * @brief 캐릭터 엔티티의 생성자입니다.
	 * 
	 * @param camera 카메라 엔티티입니다.
	 */
	Character(Camera* camera);


	/**
	 * @brief 캐릭터 엔티티의 가상 소멸자입니다.
	 */
	virtual ~Character();


	/**
	 * @brief 캐릭터 엔티티의 복사 생성자 및 대입 연산자를 명시적으로 삭제합니다.
	 */
	DISALLOW_COPY_AND_ASSIGN(Character);


	/**
	 * @brief 캐릭터 엔티티를 업데이트합니다.
	 *
	 * @param deltaSeconds 델타 시간 값입니다.
	 */
	virtual void Tick(float deltaSeconds);


	/**
	 * @brief 캐릭터 엔티티 내의 리소스를 할당 해제합니다.
	 */
	virtual void Release();


	/**
	 * @brief 캐릭터의 메시 리소스 목록을 얻습니다.
	 * 
	 * @return 캐릭터의 메시 리소스 목록 참조자를 반환합니다.
	 */
	std::vector<SkinnedMesh*>& GetMeshes() { return meshes_; }


	/**
	 * @brief 캐릭터의 메터리얼(재질)을 얻습니다.
	 * 
	 * @return 캐릭터의 메터리얼(재질) 참조자를 반환합니다.
	 */
	ITexture2D* GetMaterial() { return material_; }


	/**
	 * @brief 캐릭터의 크로스 페이드 컨트롤러를 얻습니다.
	 * 
	 * @return 캐릭터의 크로스 페이드 컨트롤러 참조자를 반환합니다.
	 */
	CrossFadeController& GetCrossFadeController() { return crossFadeController_; }


private:
	/**
	 * @brief 카메라 엔티티입니다.
	 */
	Camera* camera_ = nullptr;


	/**
	 * @brief 스키닝 메시 리소스입니다.
	 */
	std::vector<SkinnedMesh*> meshes_;


	/**
	 * @brief 캐릭터의 메터리얼입니다.
	 */
	ITexture2D* material_ = nullptr;


	/**
	 * @brief 현재 애니메이션 클립 인덱스입니다.
	 */
	uint32_t currentClip_ = 0;


	/**
	 * @brief 애니메이션 클립입니다.
	 */
	std::vector<Clip> clips_;
	

	/**
	 * @brief 캐릭터 애니메이션의 뼈대입니다.
	 */
	Skeleton skeleton_;


	/**
	 * @brief 클립의 부드러운 전환을 위한 크로스 페이드 컨트롤러입니다.
	 */
	CrossFadeController crossFadeController_;


	/**
	 * @brief 컨트롤 엔티티의 UI 위치입니다.
	 */
	ImVec2 location_;


	/**
	 * @brief 컨트롤 엔티티의 UI 크기입니다.
	 */
	ImVec2 size_;


	/**
	 * @brief 컨트롤 엔티티의 UI 옵션 플래그입니다.
	 */
	ImGuiWindowFlags flags_;
};