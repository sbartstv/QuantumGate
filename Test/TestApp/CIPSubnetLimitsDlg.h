// This file is part of the QuantumGate project. For copyright and
// licensing information refer to the license file(s) in the project root.

#pragma once

#include "CDialogBase.h"

class CIPSubnetLimitsDlg : public CDialogBase
{
	DECLARE_DYNAMIC(CIPSubnetLimitsDlg)

public:
	CIPSubnetLimitsDlg(CWnd* pParent = nullptr);
	virtual ~CIPSubnetLimitsDlg();

	void SetAccessManager(QuantumGate::AccessManager* am) noexcept;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IPSUBNET_LIMITS_DIALOG };
#endif

protected:
	virtual BOOL OnInitDialog();
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	
	afx_msg void OnBnClickedAddLimit();
	afx_msg void OnCbnSelChangeTypeCombo();
	afx_msg void OnEnChangeCIDR();
	afx_msg void OnEnChangeMaxConnections();
	afx_msg void OnLvnItemChangedIPSubnetLimitList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedRemoveLimit();

private:
	void UpdateIPSubnetLimitList() noexcept;
	void UpdateControls() noexcept;

private:
	QuantumGate::AccessManager* m_AccessManager{ nullptr };
};
